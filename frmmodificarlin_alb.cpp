#include "frmmodificarlin_alb.h"
#include "ui_frmmodificarlin_alb.h"
#include "albaran.h"
#include "articulo.h"



FrmModificarLin_alb::FrmModificarLin_alb(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FrmModificarLin_alb)
{
    ui->setupUi(this);
}

FrmModificarLin_alb::~FrmModificarLin_alb()
{
    delete ui;
}

void FrmModificarLin_alb::on_txtCodigo_editingFinished()
{
    if (!ui->txtCodigo->text().isEmpty()) {
        if (ui->txtDescripcion->text().isEmpty()) {
            Articulo *oArt =  new Articulo();

            oArt->Recuperar("Select * from articulos where cCodigo = '"+ui->txtCodigo->text()+"'");
            ui->txtCodigo->setText(oArt->getcCodigo());
            ui->txtDescripcion->setText(oArt->getcDescripcion());
            ui->txtPVP->setText(Configuracion_global->FormatoNumerico(QString::number(oArt->getrTarifa1(),'f',2)));
            ui->txtSubTotal->setText(Configuracion_global->FormatoNumerico(QString::number(oArt->getrTarifa1(),'f',2)));
            if (oArt->getrDto() > ui->txtPorcDto->text().toDouble()) {
                ui->txtPorcDto->setText(Configuracion_global->FormatoNumerico(QString::number(oArt->getrDto(),'f',0)));
            }
            ui->txtPorcIVA->setText(QString::number(oArt->getnTipoIva(),'f',0));
            delete oArt;
        }
        CalcularTotal();
    }
}

void FrmModificarLin_alb::PonerCampos(int ID_Lin)
{
    this->nId = ID_Lin;
    QSqlQuery *Mod_linAlb = new QSqlQuery(QSqlDatabase::database("empresa"));

    Configuracion_global->CargarDatos();
    Mod_linAlb->prepare("Select * from lin_alb where id = :nID");
    Mod_linAlb->bindValue(":nID",this->nId);
    if(Mod_linAlb->exec()){
        QSqlRecord record = Mod_linAlb->record();
        Mod_linAlb->next();
        record = Mod_linAlb->record();
        ui->txtCodigo->setText(record.field("cCodigo").value().toString());
        ui->txtCantidad->setText(record.field("nCantidad").value().toString());
        ui->txtDescripcion->setText(record.field("cDescripcion").value().toString());
        ui->txtPVP->setText(Configuracion_global->FormatoNumerico(record.field("rPvp").value().toString()));
        ui->txtPorcDto->setText(record.field("nDto").value().toString());
        ui->txtDTO->setText(Configuracion_global->FormatoNumerico(record.field("rDto").value().toString()));
        ui->txtSubTotal->setText(Configuracion_global->FormatoNumerico(record.field("rSubTotal").value().toString()));
        ui->txtTotal->setText(Configuracion_global->FormatoNumerico(record.field("rTotal").value().toString()));
        ui->txtPorcIVA->setText(Configuracion_global->FormatoNumerico(record.field("nPorcIva").value().toString()));
    }
    delete Mod_linAlb;
}
void FrmModificarLin_alb::CalcularTotal()
{

    // Calculo totales línea
    double impDto,impTot,impSubtotal;
    impSubtotal = (ui->txtCantidad->text().replace(".","").toDouble() * ui->txtPVP->text().replace(".","").toDouble());
    ui->txtSubTotal->setText(Configuracion_global->FormatoNumerico(QString::number(impSubtotal,'f',2)));
    impDto = (ui->txtSubTotal->text().replace(".","").toDouble() * ui->txtPorcDto->text().toDouble())/100 ;
    ui->txtDTO->setText(Configuracion_global->FormatoNumerico(QString::number(impDto,'f',2)));
    impTot = ui->txtSubTotal->text().replace(".","").toDouble() - ui->txtDTO->text().replace(".","").toDouble();
    ui->txtTotal->setText(Configuracion_global->FormatoNumerico(QString::number(impTot,'f',2)));
}

void FrmModificarLin_alb::on_pushButton_clicked()
{
    Albaran *oAlbaran = new Albaran();
    oAlbaran->ModificarLineaAlbaran(this->nId,ui->txtCodigo->text(),ui->txtCantidad->text().toDouble(),
                                    ui->txtDescripcion->text(),ui->txtPVP->text().replace(".","").toDouble(),
                                    ui->txtSubTotal->text().replace(".","").toDouble(),ui->txtPorcDto->text().toDouble(),
                                    ui->txtDTO->text().replace(".","").toDouble(),ui->txtTotal->text().replace(".","").toDouble(),
                                    ui->txtPorcIVA->text().toDouble());

    delete oAlbaran;

}

void FrmModificarLin_alb::on_txtCantidad_editingFinished()
{
    CalcularTotal();
}

void FrmModificarLin_alb::on_txtPVP_editingFinished()
{
    CalcularTotal();
}

void FrmModificarLin_alb::on_txtPorcDto_editingFinished()
{
    CalcularTotal();
}
