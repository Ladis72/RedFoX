#include "frmalbaran.h"
#include "ui_frmalbaran.h"
#include "albaran.h"
#include "cliente.h"
#include "columnamoneda.h"
#include "configuracion.h"

Albaran *oAlbaran = new Albaran();
Cliente *oCliente2 = new Cliente();
ColumnaMoneda *Columna1 = new ColumnaMoneda();


FrmAlbaran::FrmAlbaran(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FrmAlbaran)
{
    ui->setupUi(this);
    // Pongo valores por defecto
    ui->lblFacturado->setVisible(false);
    ui->lblImpreso->setVisible(false);
    ui->lblNumFactura->setVisible(false);
    ui->txtcNumFra->setVisible(false);
    // valores edicion
    ui->txtcCodigoArticulo->setFocus();
    BloquearCampos();
}

FrmAlbaran::~FrmAlbaran()
{
    delete ui;
}

void FrmAlbaran::lineasVentas()
{
    // lineas de ventas
    QString cSQL;
    QString cId;

    cId = cId.number(oAlbaran->Getid());
     cSQL ="select id,cCodigo,nCantidad,cDescripcion,rPvp,rSubtotal,nDto,rDto,rTotal, nPorcIva from lin_alb "
             " where Id_Cab = "+cId;
     QSqlQueryModel *ModelLin_alb = new QSqlQueryModel();
     ModelLin_alb->setQuery(cSQL,QSqlDatabase::database("empresa"));
     ui->Lineas->setModel(ModelLin_alb);
      //Creamos Objeto de la clase Cabecera para las cabeceras horizontales
     QHeaderView *Cabecera = new QHeaderView(Qt::Horizontal,this);
     // Le decimos a nuestro objeto QTableView  que use la instancia de QHeaderView que acabamos de crear.
     ui->Lineas->setHorizontalHeader(Cabecera);
     /*Ponemos el tamaño deseado para cada columna, teniendo en cuenta que la primera columna es la "0". (en nuestro caso está oculta ya que muestra el id de la tabla y esto no nos interesa que lo vea el usuario */
     Cabecera->setResizeMode(0,QHeaderView::Fixed);
     Cabecera->resizeSection(0,0);
     Cabecera->setResizeMode(1,QHeaderView::Fixed);
     Cabecera->resizeSection(1,85);
     Cabecera->setResizeMode(2,QHeaderView::Fixed);
     Cabecera->resizeSection(2,65);
     Cabecera->setResizeMode(3,QHeaderView::Fixed);
     Cabecera->resizeSection(3,413);
     Cabecera->setResizeMode(4,QHeaderView::Fixed);
     Cabecera->resizeSection(4,120);
     Cabecera->setResizeMode(9,QHeaderView::Fixed);
     Cabecera->resizeSection(9,35);
     ModelLin_alb->setHeaderData(1, Qt::Horizontal, QObject::tr("CÓDIGO"));
     ModelLin_alb->setHeaderData(2, Qt::Horizontal, QObject::tr("CANTIDAD"));
     ModelLin_alb->setHeaderData(3, Qt::Horizontal, QObject::tr("DESCRIPCIÓN"));
     ModelLin_alb->setHeaderData(4, Qt::Horizontal, QObject::tr("PVP"));
     ModelLin_alb->setHeaderData(5, Qt::Horizontal, QObject::tr("SUBTOTAL"));
     ModelLin_alb->setHeaderData(6, Qt::Horizontal, QObject::tr("%DTO"));
     ModelLin_alb->setHeaderData(7, Qt::Horizontal, QObject::tr("DTO"));
     ModelLin_alb->setHeaderData(8, Qt::Horizontal, QObject::tr("BASE"));
     ModelLin_alb->setHeaderData(9, Qt::Horizontal, QObject::tr("%IVA"));

    // Hacemos visible la cabecera
     Cabecera->setVisible(true);
     // Delegamos el control contenido en las columnas al nuevo objeto ColumnaGrid
     ui->Lineas->setItemDelegateForColumn(4, Columna1);
     ui->Lineas->setItemDelegateForColumn(5, Columna1);
     ui->Lineas->setItemDelegateForColumn(6, Columna1);
     ui->Lineas->setItemDelegateForColumn(7, Columna1);
     ui->Lineas->setItemDelegateForColumn(8, Columna1);
}

void FrmAlbaran::LLenarCampos() {
    int lEstado;
    Configuracion *o_configuracion = new Configuracion();
    ui->txtcCodigoCliente->setText(oAlbaran->getcCodigoCliente());
    ui->txtcAlbaran->setText(QString::number(oAlbaran->getnAlbaran()));
    ui->txtdFecha->setDate(oAlbaran->getdFecha());
    ui->txtdFechaFactura->setDate(oAlbaran->getdFechaFactura());
    ui->txtcCliente->setText(oAlbaran->getcCliente());
    ui->txtcDireccion->setText(oAlbaran->getcDireccion());
    ui->txtcDireccion2->setText(oAlbaran->getcDireccion2());
    ui->txtcCp->setText(oAlbaran->getcCp());
    ui->txtcPoblacion->setText(oAlbaran->getcPoblacion());
    ui->txtcProvincia->setText(oAlbaran->getcProvincia());
    ui->txtcPais->setText(oAlbaran->getcPais());
    ui->txtcCif->setText(oAlbaran->getcCif());
    ui->txtrSubtotal->setText(o_configuracion->FormatoNumerico( QString::number(oAlbaran->getrSubtotal(),'f',2)));
    ui->txtnDto->setText(o_configuracion->FormatoNumerico(QString::number(oAlbaran->getnDto(),'f',2)));
    ui->txtrImporteDescuento->setText(o_configuracion->FormatoNumerico(QString::number(oAlbaran->getrImporteDescuento(),'f',2)));
    ui->txtrBase->setText(o_configuracion->FormatoNumerico(QString::number( oAlbaran->getrBase(),'f',2)));
    ui->txtnIva_2->setText(o_configuracion->FormatoNumerico(QString::number( oAlbaran->getnIva(),'f',2)));
    ui->txtrImporteIva->setText(o_configuracion->FormatoNumerico(QString::number(oAlbaran->getrImporteIva(),'f',2)));
    ui->txtrTotal->setText(o_configuracion->FormatoNumerico(QString::number(oAlbaran->getrTotal(),'f',2)));
    lEstado = oAlbaran->getlImpreso();
    if((lEstado == 1)) {
        ui->lblImpreso->setVisible(true);
    } else {
        ui->lblImpreso->setVisible(false);
    }
    lEstado = oAlbaran->getlFacturado();
    if ((lEstado == 1)) {
        ui->lblFacturado->setVisible(true);
        ui->txtdFechaFactura->setVisible(true);
        ui->txtcNumFra->setVisible(true);
    } else {
        ui->lblFacturado->setVisible(false);
        ui->txtdFechaFactura->setVisible(false);
        ui->txtcNumFra->setVisible(false);

    }
    ui->txttComentario->setText(oAlbaran->gettComentario());
    ui->txtrBase1->setText(o_configuracion->FormatoNumerico(QString::number(oAlbaran->getrBase1(),'f',2)));
    ui->txtrBase2->setText(o_configuracion->FormatoNumerico(QString::number(oAlbaran->getrBase2(),'f',2)));
    ui->txtrBase3->setText(o_configuracion->FormatoNumerico(QString::number(oAlbaran->getrBase3(),'f',2)));
    ui->txtrBase4->setText(o_configuracion->FormatoNumerico(QString::number(oAlbaran->getrBase4(),'f',2)));
    ui->txtnPorcentajeIva1->setText(QString::number(oAlbaran->getnPorcentajeIVA1()));
    ui->txtnPorcentajeIva2->setText(QString::number(oAlbaran->getnPorcentajeIVA2()));
    ui->txtnPorcentajeIva3->setText(QString::number(oAlbaran->getnPorcentajeIVA3()));
    ui->txtnPorcentajeIva4->setText(QString::number(oAlbaran->getnPorcentajeIVA4()));
    ui->txtrIVA1->setText(o_configuracion->FormatoNumerico(QString::number(oAlbaran->getrIVA1(),'f',2)));
    ui->txtrIVA2->setText(o_configuracion->FormatoNumerico(QString::number(oAlbaran->getrIVA2(),'f',2)));
    ui->txtrIVA3->setText(o_configuracion->FormatoNumerico(QString::number(oAlbaran->getrIVA3(),'f',2)));
    ui->txtrIVA4->setText(o_configuracion->FormatoNumerico(QString::number(oAlbaran->getrIVA4(),'f',2)));
    ui->txtrTotal1->setText(o_configuracion->FormatoNumerico(QString::number(oAlbaran->getrTotal1(),'f',2)));
    ui->txtrTotal2->setText(o_configuracion->FormatoNumerico(QString::number(oAlbaran->getrTotal2(),'f',2)));
    ui->txtrTotal3->setText(o_configuracion->FormatoNumerico(QString::number(oAlbaran->getrTotal3(),'f',2)));
    ui->txtrTotal4->setText(o_configuracion->FormatoNumerico(QString::number(oAlbaran->getrTotal4(),'f',2)));
    ui->txtnRec1->setText(o_configuracion->FormatoNumerico(QString::number(oAlbaran->getnRec1(),'f',2)));
    ui->txtnRec2->setText(o_configuracion->FormatoNumerico(QString::number(oAlbaran->getnRec2(),'f',2)));
    ui->txtnRec3->setText(o_configuracion->FormatoNumerico(QString::number(oAlbaran->getnRec3(),'f',2)));
    ui->txtnRec4->setText(o_configuracion->FormatoNumerico(QString::number(oAlbaran->getnRec4(),'f',2)));
    ui->txtrRecargoEq1->setText(o_configuracion->FormatoNumerico(QString::number(oAlbaran->getrRecargoEq1(),'f',2)));
    ui->txtrRecargoEq2->setText(o_configuracion->FormatoNumerico(QString::number(oAlbaran->getrRecargoEq2(),'f',2)));
    ui->txtrRecargoEq3->setText(o_configuracion->FormatoNumerico(QString::number(oAlbaran->getrRecargoEq3(),'f',2)));
    ui->txtrRecargoEq4->setText(o_configuracion->FormatoNumerico(QString::number(oAlbaran->getrRecargoEq4(),'f',2)));
    ui->txtrTotalRecargoEq->setText(o_configuracion->FormatoNumerico(QString::number(oAlbaran->getrRecargoEqTotal(),'f',2)));
    ui->txtcPedidoCliente->setText(oAlbaran->getcPedidoCli());

    delete o_configuracion;
    // cargamos líneas de ventas
   lineasVentas();


}
void FrmAlbaran::LLenarCamposCliente()
{
    ui->txtcCodigoCliente->setText(oCliente2->getcCodigoCliente());
    ui->txtcCliente->setText(oCliente2->getcNombreFiscal());
    ui->txtcDireccion->setText(oCliente2->getcDireccion1());
    ui->txtcDireccion2->setText(oCliente2->getcDireccion2());
    ui->txtcCp->setText(oCliente2->getcCP());
    ui->txtcPoblacion->setText(oCliente2->getcPoblacion());
    ui->txtcProvincia->setText(oCliente2->getcProvincia());
    ui->txtcPais->setText(oCliente2->getcPais());
    ui->txtcCif->setText(oCliente2->getcCifNif());
}

void FrmAlbaran::VaciarCampos() {
    QDate dFecha;
    Configuracion *o_configuracion = new Configuracion();
    ui->txtcCodigoCliente->setText("");
    ui->txtcAlbaran->setText("");
    ui->txtdFecha->setDate(dFecha.currentDate());
    ui->txtdFechaFactura->setDate(dFecha.currentDate());
    ui->txtcCliente->setText("");
    ui->txtcDireccion->setText("");
    ui->txtcDireccion2->setText("");
    ui->txtcCp->setText("");
    ui->txtcPoblacion->setText("");
    ui->txtcProvincia->setText("");
    ui->txtcPais->setText("");
    ui->txtcCif->setText("");
    ui->txtrSubtotal->setText(0);
    ui->txtnDto->setText(0);
    ui->txtnDtoPP->setText(0);
    ui->txtrImporteDescuento->setText("0,00");
    ui->txtrImporteDescuentoPP->setText("0,00");
    ui->txtrBase->setText("0,00");
    ui->txtnIva_2->setText(0);
    ui->txtrImporteIva->setText("0,00");
    ui->txtrTotal->setText("0,00");
    ui->lblImpreso->setVisible(false);
    ui->lblFacturado->setVisible(false);
    ui->lblNumFactura->setVisible(false);
    ui->txtcNumFra->setVisible(false);
    ui->txttComentario->setText("");
    ui->txtrBase1->setText(0);
    ui->txtrBase2->setText(0);
    ui->txtrBase3->setText(0);
    ui->txtrBase4->setText(0);
    ui->txtnPorcentajeIva1->setText(QString::number(o_configuracion->nIVA1));
    ui->txtnPorcentajeIva2->setText(QString::number(o_configuracion->nIVA2));
    ui->txtnPorcentajeIva3->setText(QString::number(o_configuracion->nIVA3));
    ui->txtnPorcentajeIva4->setText(QString::number(o_configuracion->nIVA4));
    ui->txtnRec1->clear();
    ui->txtnRec2->clear();
    ui->txtnRec3->clear();
    ui->txtnRec4->clear();
    ui->txtrIVA1->setText(0);
    ui->txtrIVA2->setText(0);
    ui->txtrIVA3->setText(0);
    ui->txtrIVA4->setText(0);
    ui->txtrTotal1->setText(0);
    ui->txtrTotal2->setText(0);
    ui->txtrTotal3->setText(0);
    ui->txtrTotal4->setText(0);
    ui->txtrRecargoEq1->setText(0);
    ui->txtrRecargoEq2->setText(0);
    ui->txtrRecargoEq3->setText(0);
    ui->txtrRecargoEq4->setText(0);
    ui->txtrTotalRecargoEq->setText(0);
    ui->txtrACuenta->setText("0,00");
    ui->txtcPedidoCliente->setText("");
    delete o_configuracion;
}

void FrmAlbaran::BloquearCampos()
{
    QList<QLineEdit *> lineEditList = this->findChildren<QLineEdit *>();
    QLineEdit *lineEdit;
    foreach (lineEdit, lineEditList) {
        lineEdit->setReadOnly(true);
        //qDebug() << lineEdit->objectName();
    }
    // ComboBox
    QList<QComboBox *> ComboBoxList = this->findChildren<QComboBox *>();
    QComboBox *ComboBox;
    foreach (ComboBox, ComboBoxList) {
        ComboBox->setEnabled(false);
        //qDebug() << lineEdit->objectName();
    }
    /*
//    // SpinBox
//    QList<QSpinBox *> SpinBoxList = this->findChildren<QSpinBox *>();
//    QSpinBox *SpinBox;
//    foreach (SpinBox, SpinBoxList) {
//        SpinBox->setReadOnly(true);
//        //qDebug() << lineEdit->objectName();
//    }
//    // DoubleSpinBox
//    QList<QDoubleSpinBox *> DSpinBoxList = this->findChildren<QDoubleSpinBox *>();
//    QDoubleSpinBox *DSpinBox;
//    foreach (DSpinBox, DSpinBoxList) {
//        DSpinBox->setReadOnly(true);
//        //qDebug() << lineEdit->objectName();
//    } */
    // CheckBox
    QList<QCheckBox *> CheckBoxList = this->findChildren<QCheckBox *>();
    QCheckBox *CheckBox;
    foreach (CheckBox, CheckBoxList) {
        CheckBox->setEnabled(false);
        //qDebug() << lineEdit->objectName();
    }
    // QTextEdit
    QList<QTextEdit *> textEditList = this->findChildren<QTextEdit *>();
    QTextEdit *textEdit;
    foreach (textEdit,textEditList) {
        textEdit->setReadOnly(true);
        //qDebug() << lineEdit->objectName();
    }
    // QDateEdit
    QList<QDateEdit *> DateEditList = this->findChildren<QDateEdit *>();
    QDateEdit *DateEdit;
    foreach (DateEdit, DateEditList) {
        DateEdit->setEnabled(false);
        //qDebug() << lineEdit->objectName();
    }

    ui->btnAnadir->setEnabled(true);
    ui->btnAnterior->setEnabled(true);
   // ui->btnBorrar->setEnabled(true);
    ui->btnBuscar->setEnabled(true);
    ui->btnCerrar->setEnabled(true);
    ui->btnDeshacer->setEnabled(false);
    ui->btnEditar->setEnabled(true);
    ui->btnGuardar->setEnabled(false);
    ui->btnSiguiente->setEnabled(true);
    ui->botBorrarLinea->setEnabled(false);
    ui->botEditarLinea->setEnabled(false);
    ui->botBuscarCliente->setEnabled(false);

}

void FrmAlbaran::DesbloquearCampos()
{
    // LineEdit
    QList<QLineEdit *> lineEditList = this->findChildren<QLineEdit *>();
    QLineEdit *lineEdit;
    foreach (lineEdit, lineEditList) {
        lineEdit->setReadOnly(false);
        //qDebug() << lineEdit->objectName();
    }
    // ComboBox
    QList<QComboBox *> ComboBoxList = this->findChildren<QComboBox *>();
    QComboBox *ComboBox;
    foreach (ComboBox, ComboBoxList) {
        ComboBox->setEnabled(true);
        //qDebug() << lineEdit->objectName();
    }
//    // SpinBox
//    QList<QSpinBox *> SpinBoxList = this->findChildren<QSpinBox *>();
//    QSpinBox *SpinBox;
//    foreach (SpinBox, SpinBoxList) {
//        SpinBox->setReadOnly(false);
//        //qDebug() << lineEdit->objectName();
//    }
//    // DoubleSpinBox
//    QList<QDoubleSpinBox *> DSpinBoxList = this->findChildren<QDoubleSpinBox *>();
//    QDoubleSpinBox *DSpinBox;
//    foreach (DSpinBox, DSpinBoxList) {
//        DSpinBox->setReadOnly(false);
//        //qDebug() << lineEdit->objectName();
//    }
    // CheckBox
    QList<QCheckBox *> CheckBoxList = this->findChildren<QCheckBox *>();
    QCheckBox *CheckBox;
    foreach (CheckBox, CheckBoxList) {
        CheckBox->setEnabled(true);
        //qDebug() << lineEdit->objectName();
    }
    // QTextEdit
    QList<QTextEdit *> textEditList = this->findChildren<QTextEdit *>();
    QTextEdit *textEdit;
    foreach (textEdit,textEditList) {
        textEdit->setReadOnly(false);
        //qDebug() << lineEdit->objectName();
    }
    // QDateEdit
    QList<QDateEdit *> DateEditList = this->findChildren<QDateEdit *>();
    QDateEdit *DateEdit;
    foreach (DateEdit, DateEditList) {
        DateEdit->setEnabled(true);
        //qDebug() << lineEdit->objectName();
    }
    ui->btnAnadir->setEnabled(false);
    ui->btnAnterior->setEnabled(false);
   // ui->btnBorrar->setEnabled(false);
    ui->btnBuscar->setEnabled(false);
    ui->btnCerrar->setEnabled(false);
    ui->btnDeshacer->setEnabled(true);
    ui->btnEditar->setEnabled(false);
    ui->btnGuardar->setEnabled(true);
    ui->btnSiguiente->setEnabled(false);
    ui->botBorrarLinea->setEnabled(true);
    ui->botEditarLinea->setEnabled(true);
    ui->botBuscarCliente->setEnabled(true);
}

void FrmAlbaran::LLenarAlbaran() {
    oAlbaran->setcCodigoCliente(ui->txtcCodigoCliente->text());
    oAlbaran->setnAlbaran(ui->txtcAlbaran->text().toInt());
    oAlbaran->setdFecha(ui->txtdFecha->date());
    oAlbaran->setdFechaFactura(ui->txtdFechaFactura->date());
    oAlbaran->setcCliente(ui->txtcCliente->text());
    oAlbaran->setcDireccion(ui->txtcDireccion->text());
    oAlbaran->setcDireccion2(ui->txtcDireccion2->text());
    oAlbaran->setcCp(ui->txtcCp->text());
    oAlbaran->setcPoblacion(ui->txtcPoblacion->text());
    oAlbaran->setcProvincia(ui->txtcProvincia->text());
    oAlbaran->setcPais(ui->txtcPais->text());
    oAlbaran->setcCif(ui->txtcCif->text());
    oAlbaran->setrSubtotal(ui->txtrSubtotal->text().replace(".","").toDouble());
    oAlbaran->setnDto(ui->txtnDto->text().replace(".","").toDouble());
    oAlbaran->setrImporteDescuento(ui->txtrImporteDescuento->text().replace(".","").toDouble());
    oAlbaran->setrBase(ui->txtrBase->text().replace(".","").toDouble());
    oAlbaran->setrImporteIva(ui->txtrImporteIva->text().replace(".","").toDouble());
    oAlbaran->setrTotal(ui->txtrTotal->text().replace(".","").toDouble());
    oAlbaran->settComentario(ui->txttComentario->toPlainText());
    oAlbaran->setrBase1(ui->txtrBase1->text().replace(".","").toDouble());
    oAlbaran->setrBase2(ui->txtrBase2->text().replace(".","").toDouble());
    oAlbaran->setrBase3(ui->txtrBase3->text().replace(".","").toDouble());
    oAlbaran->setrBase4(ui->txtrBase4->text().replace(".","").toDouble());
    oAlbaran->setnPorcentajeIVA1(ui->txtnPorcentajeIva1->text().replace(".","").toDouble());
    oAlbaran->setnPorcentajeIVA2(ui->txtnPorcentajeIva2->text().replace(".","").toDouble());
    oAlbaran->setnPorcentajeIVA3(ui->txtnPorcentajeIva3->text().replace(".","").toDouble());
    oAlbaran->setnPorcentajeIVA4(ui->txtnPorcentajeIva4->text().replace(".","").toDouble());
    oAlbaran->setrIVA1(ui->txtrIVA1->text().replace(".","").toDouble());
    oAlbaran->setrIVA2(ui->txtrIVA2->text().replace(".","").toDouble());
    oAlbaran->setrIVA3(ui->txtrIVA3->text().replace(".","").toDouble());
    oAlbaran->setrIVA4(ui->txtrIVA4->text().replace(".","").toDouble());
    oAlbaran->setrTotal1(ui->txtrTotal1->text().replace(".","").toDouble());
    oAlbaran->setrTotal2(ui->txtrTotal2->text().replace(".","").toDouble());
    oAlbaran->setrTotal3(ui->txtrTotal3->text().replace(".","").toDouble());
    oAlbaran->setrTotal4(ui->txtrTotal4->text().replace(".","").toDouble());
    oAlbaran->setnRec1(ui->txtnRec1->text().replace(".","").toDouble());
    oAlbaran->setnRec2(ui->txtnRec2->text().replace(".","").toDouble());
    oAlbaran->setnRec3(ui->txtnRec3->text().replace(".","").toDouble());
    oAlbaran->setnRec4(ui->txtnRec4->text().replace(".","").toDouble());
    oAlbaran->setrRecargoEq1(ui->txtrRecargoEq1->text().replace(".","").toDouble());
    oAlbaran->setrRecargoEq2(ui->txtrRecargoEq2->text().replace(".","").toDouble());
    oAlbaran->setrRecargoEq3(ui->txtrRecargoEq3->text().replace(".","").toDouble());
    oAlbaran->setrRecargoEq4(ui->txtrRecargoEq4->text().replace(".","").toDouble());
    oAlbaran->setrRecargoEqTotal(ui->txtrTotalRecargoEq->text().replace(".","").toDouble());

    oAlbaran->setcPedidoCli(ui->txtcPedidoCliente->text());


}

void FrmAlbaran::on_btnSiguiente_clicked()
{
    int nAlbaran = oAlbaran->getnAlbaran();
    oAlbaran->RecuperarAlbaran("Select * from cab_alb where nAlbaran >'"+QString::number(nAlbaran)+"' order by nAlbaran  limit 0,1 ");
    LLenarCampos();
}

void FrmAlbaran::on_btnAnterior_clicked()
{
    int nAlbaran = oAlbaran->getnAlbaran();
    oAlbaran->RecuperarAlbaran("Select * from cab_alb where nAlbaran <'"+QString::number(nAlbaran)+"' order by nAlbaran desc limit 0,1 ");
    LLenarCampos();
}

void FrmAlbaran::on_btnAnadir_clicked()
{
    VaciarCampos();
    LLenarAlbaran();
    oAlbaran->AnadirAlbaran();
    LLenarCampos();
    DesbloquearCampos();
    ui->txtcCodigoCliente->setFocus();
}

void FrmAlbaran::on_botBuscarCliente_clicked()
{
    FrmBuscarCliente BuscarClientes;
    BuscarClientes.exec();
    int nId = BuscarClientes.DevolverID();
    QString cId = QString::number(nId);
    oAlbaran->setiId_Cliente(cId.toInt());
    oCliente2->Recuperar("Select * from clientes where id ="+cId+" order by id limit 0,1 ");
    LLenarCamposCliente();
}



void FrmAlbaran::on_btnEditar_clicked()
{
    if (!oAlbaran->getlFacturado()) {
        DesbloquearCampos();
    } else {
        QMessageBox::warning(NULL,tr("Editar Albarán"),tr("No se puede editar un albarán que ha sido facturado, solo los NO facturados se pueden editar")+
                             tr("<p><b> Si necesita modificar algo genere una factura nueva y realice el abono correspondiente</b>")+
                                tr("y luego si es preciso realice un nuevo albarán y facture de nuevo "),tr("OK"));
    }

}

void FrmAlbaran::on_btnGuardar_clicked()
{
    int nId = oAlbaran->Getid();
    if (ui->txtcAlbaran->text().trimmed() =="0")
        ui->txtcAlbaran->setText(QString::number(oAlbaran->NuevoNumeroAlbaran()));
    LLenarAlbaran();
    BloquearCampos();
    oAlbaran->GuardarAlbaran(nId);
    oAlbaran->RecuperarAlbaran("Select * from cab_alb where Id="+QString::number(nId)+"  limit 0,1 ");
    LLenarCampos();
}