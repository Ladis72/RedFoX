#include "frmtarifas.h"
#include "ui_frmtarifas.h"

FrmTarifas::FrmTarifas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FrmTarifas)
{
    ui->setupUi(this);
    QSqlQueryModel *modelo = new QSqlQueryModel(this);
    modelo->setQuery("Select descripcion from codigotarifa",Configuracion_global->groupDB);
    ui->listaTarifa->setModel(modelo);


    //-----------
    // CONEXIONES
    //-----------
    connect(ui->listaTarifa,SIGNAL(clicked(QModelIndex)),this,SLOT(cargarDatosTarifa(QModelIndex)));
    connect(ui->txtPVPDivisa,SIGNAL(editingFinished()),Configuracion_global,SLOT(format_text()));
    connect(ui->txtPVPDivisa,SIGNAL(editingFinished()),this,SLOT(cambiar_precio_editingfinished()));
    connect(ui->btnAceptar,SIGNAL(clicked()),this,SLOT(aceptar()));
    connect(ui->spinMargen,SIGNAL(valueChanged(double)),this,SLOT(calcular_precio(double)));


    //-------------------------------
    // CAMBIO DIVISA
    //-------------------------------
    connect(Configuracion_global,SIGNAL(cambioReady(float)),this,SLOT(asignarcambiodivisa(float)));
    //   Configuracion_global->getCambio("EUR","USD",1);

    ui->spinMargen->setValue(Configuracion_global->margen);
    ui->spinmargen_minimo->setValue(Configuracion_global->margen_minimo);

    //---------------------
    //  Importados SP
    //---------------------
    ui->frame_dtos_sp->setVisible(Configuracion_global->importado_sp);


}

FrmTarifas::~FrmTarifas()
{
    delete ui;
}

void FrmTarifas::capturar_coste(float Coste)
{
    this->coste = Coste;
    ui->txtCosteLocal->setText(Configuracion_global->toFormatoMoneda(QString::number(Coste)));
}

void FrmTarifas::capturar_datos(int id, QString costeLocal){
    ui->listaTarifa->hide();
    QSqlQuery queryTarifas(Configuracion_global->groupDB);
    if(!queryTarifas.exec("select * from tarifas where id="+QString::number(id))){
        QMessageBox::warning(this,tr("Editar"),
                             tr("Ocurrió un error al recuperar los datos: %1").arg(queryTarifas.lastError().text()));
    }else {
        if (queryTarifas.next())
        {
            QSqlQuery queryGrupotarifa(Configuracion_global->groupDB);
            int nId = queryTarifas.record().value("id_codigo_tarifa").toInt();
            QString cSQL1 = "select * from codigotarifa where id=";
            cSQL1.append(QString::number(nId));
            qDebug() << cSQL1;
            if(queryGrupotarifa.exec(cSQL1)){
                queryGrupotarifa.next();
                ui->txtCodTarifa->setText(queryGrupotarifa.record().field("codigo_tarifa").value().toString());
                ui->txtDescTarifa->setText(queryGrupotarifa.record().field("descripcion").value().toString());
            }
            ui->txtPais->setText(Configuracion_global->Devolver_pais(queryTarifas.record().field("id_pais").value().toInt()));
            ui->txtMoneda->setText(Configuracion_global->Devolver_moneda(queryTarifas.record().value("id_monedas").toInt()));
            ui->txtPVPDivisa->setText(Configuracion_global->toFormatoMoneda(queryTarifas.record().value("pvp").toString()));
            ui->txtCosteLocal->setText(costeLocal);
            if(queryTarifas.record().value("margen").toDouble() == 0)
                ui->spinMargen->setValue(Configuracion_global->margen);
            else
                ui->spinMargen->setValue(queryTarifas.record().field("margen").value().toDouble());
            if (queryTarifas.record().value("margen_minimo") == 0)
                ui->spinmargen_minimo->setValue(Configuracion_global->margen_minimo);
            else
                ui->spinmargen_minimo->setValue(queryTarifas.record().field("margen_minimo").value().toDouble());

            this->id_tarifa = queryTarifas.record().field("id").value().toInt();
            this->id_pais = queryTarifas.record().field("id_pais").value().toInt();
            this->id_moneda = queryTarifas.record().field("id_monedas").value().toInt();
            this->codigoTarifa = queryTarifas.record().field("codigo_tarifa").value().toString();
            this->margen = ui->spinMargen->value();
            this->margen_min = ui->spinmargen_minimo->value();
            this->coste = costeLocal.toDouble();
            this->pvpDivisa =ui->txtPVPDivisa->text().toDouble();
            this->cod_divisa = Configuracion_global->Devolver_codDivisa(queryTarifas.record().field("id_monedas").value().toInt());
            // Cargamos valor divisa desde la web
            if (Configuracion_global->divisa_local != ui->txtMoneda->text())
                Configuracion_global->getCambio(Configuracion_global->cod_divisa_local,this->cod_divisa);
            else
                asignarcambiodivisa(1);
            ui->dspin_porc_dto1->setValue(queryTarifas.record().field("porc_dto1").value().toDouble());
            ui->dspin_porc_dto2->setValue(queryTarifas.record().field("porc_dto2").value().toDouble());
            ui->dspin_porc_dto3->setValue(queryTarifas.record().field("porc_dto3").value().toDouble());
            ui->dspin_porc_dto4->setValue(queryTarifas.record().field("porc_dto4").value().toDouble());
            ui->dspin_porc_dto5->setValue(queryTarifas.record().field("porc_dto5").value().toDouble());
            ui->dspin_porc_dto6->setValue(queryTarifas.record().field("porc_dto6").value().toDouble());

        }


   }
}

void FrmTarifas::cargarDatosTarifa(QModelIndex indice)
{
    QSqlQueryModel* modelo = (QSqlQueryModel*)ui->listaTarifa->model();
    QString tarifa = modelo->record(indice.row()).value("descripcion").toString();
    QSqlQuery qTarifa(Configuracion_global->groupDB);
    qTarifa.prepare("select * from codigotarifa where descripcion ='"+tarifa+"'");

    if(qTarifa.exec()){
        qTarifa.next();

        ui->txtCodTarifa->setText(qTarifa.record().field("codigo_tarifa").value().toString());
        ui->txtDescTarifa->setText(qTarifa.record().field("descripcion").value().toString());
        ui->txtPais->setText(Configuracion_global->Devolver_pais(qTarifa.record().field("id_pais").value().toInt()));
        ui->txtMoneda->setText(Configuracion_global->Devolver_moneda(qTarifa.record().field("id_monedas").value().toInt()));
        this->id_tarifa = qTarifa.record().field("id").value().toInt();
        this->id_pais = qTarifa.record().field("id_pais").value().toInt();
        this->id_moneda = qTarifa.record().field("id_monedas").value().toInt();
        this->cod_divisa = Configuracion_global->Devolver_codDivisa(this->id_moneda);
        this->codigoTarifa = qTarifa.record().field("codigo_tarifa").value().toString();
        this->margen = ui->spinMargen->value();
        this->pvpDivisa = qTarifa.record().field("pvp").value().toDouble();
        this->margen_min = ui->spinmargen_minimo->value();
        if (Configuracion_global->divisa_local != ui->txtMoneda->text())
            Configuracion_global->getCambio(Configuracion_global->cod_divisa_local,this->cod_divisa);
        else
            asignarcambiodivisa(1);
        ui->dspin_porc_dto1->setValue(qTarifa.record().field("porc_dto1").value().toDouble());
        ui->dspin_porc_dto2->setValue(qTarifa.record().field("porc_dto2").value().toDouble());
        ui->dspin_porc_dto3->setValue(qTarifa.record().field("porc_dto3").value().toDouble());
        ui->dspin_porc_dto4->setValue(qTarifa.record().field("porc_dto4").value().toDouble());
        ui->dspin_porc_dto5->setValue(qTarifa.record().field("porc_dto5").value().toDouble());
        ui->dspin_porc_dto6->setValue(qTarifa.record().field("porc_dto6").value().toDouble());
    }
    calcular_precio(ui->spinMargen->value());

}

void FrmTarifas::asignarcambiodivisa(float valor)
{
    ui->txtValorDivisa->setText(QString::number(valor,'f',3));
    double valorLocal;
    valorLocal = (1/valor);
    ui->txtvalorLocal->setText(QString::number(valorLocal,'f',3));
    int pvpd;
    pvpd = this->pvpDivisa * ui->txtValorDivisa->text().toDouble();
    ui->txtPVPLocal->setText( QString::number(pvpd,'f',3));
    calcular_precio(ui->spinMargen->value());

}



void FrmTarifas::calcular_precio(double margen)
{
        //TODO - CALCULO DIVISA LOCAL FALLA.
        blockSignals(true);
        //NOTE 70% /0.30 - 40 /0.60
        double pvp = (ui->txtCosteLocal->text().replace(".","").replace(",",".").toDouble())/(margen/100);
        QString cPvp = Configuracion_global->toFormatoMoneda(QString::number(pvp,'f',Configuracion_global->decimales));
        this->pvpDivisa = cPvp.toDouble();
        ui->txtPVPLocal->setText(cPvp);
        double cambio_divisa =  ui->txtValorDivisa->text().toDouble();
        double valordivisa = ui->txtPVPLocal->text().replace(".","").replace(",",".").toDouble() * cambio_divisa;

        ui->txtPVPDivisa->setText(Configuracion_global->toFormatoMoneda(QString::number(valordivisa,'f',Configuracion_global->decimales)));
        this->pvpDivisa = valordivisa;
        blockSignals(false);
}



void FrmTarifas::aceptar()
{
    this->margen = ui->spinMargen->value();
    this->margen_min = ui->spinmargen_minimo->value();
    this->accept();
}


void FrmTarifas::on_txtPVPLocal_editingFinished()
{
    blockSignals(true);
    double Margen=100-((ui->txtCosteLocal->text().replace(".","").replace(",",".").toDouble()*100)/ui->txtPVPLocal->text().replace(".","").replace(",",".").toDouble());
    ui->spinMargen->setValue(Margen);
    calcular_precio(Margen);
    blockSignals(false);
}

void FrmTarifas::on_btnDesbloquearDivisa_clicked(bool checked)
{
    if (checked)
    {
        ui->txtValorDivisa->setEnabled(true);
        ui->txtvalorLocal->setEnabled(true);
        ui->txtValorDivisa->setFocus();
        if(Configuracion_global->activar_seguimiento) {
            // TODO Seguimiento cambio divisas manual
        }

    } else
    {
        ui->txtValorDivisa->setEnabled(false);
        ui->txtvalorLocal->setEnabled(false);
    }

}

void FrmTarifas::on_spinMargen_editingFinished()
{
    calcular_precio(ui->spinMargen->value());
}
