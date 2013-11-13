#include "frminsertardinerocaja.h"
#include "ui_frminsertardinerocaja.h"

FrmInsertarDineroCaja::FrmInsertarDineroCaja(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FrmInsertarDineroCaja)
{
    ui->setupUi(this);
    QSqlQueryModel* modelo = new QSqlQueryModel(this);
    modelo->setQuery("select nombre from usuarios",Configuracion_global->groupDB);
    ui->cboUsuario->setModel(modelo);
}

FrmInsertarDineroCaja::~FrmInsertarDineroCaja()
{
    delete ui;
}

void FrmInsertarDineroCaja::on_txtimporte_editingFinished()
{
    ui->txtimporte->blockSignals(true);
    ui->txtimporte->setText(Configuracion_global->toFormatoMoneda(ui->txtimporte->text()));
    ui->txtimporte->blockSignals(false);
}

void FrmInsertarDineroCaja::on_btnAceptar_clicked()
{
    QHash <QString, QVariant> h;
    QString error;
    h["concepto"] = ui->txtMotivo->toPlainText();
    int id_usuario = SqlCalls::SelectOneField("usuarios","id",QString("nombre = '%1'").arg(ui->cboUsuario->currentText()),
                                              Configuracion_global->groupDB,error).toInt();
    h["id_usuario"] = id_usuario;
    h["importe"] = Configuracion_global->MonedatoDouble(ui->txtimporte->text());
    h["fecha"]= QDate::currentDate().toString("yyyyMMdd");
    h["hora"] = QTime::currentTime().toString("hh:mm");
    h["entrada"]  = 1;
    int new_id = SqlCalls::SqlInsert(h,"e_s_caja",Configuracion_global->empresaDB,error);
    if(new_id <0)
        QMessageBox::warning(this,tr("Gestión de tickets"),tr("se produjo un error al insertar: %1").arg(error));
    else
        TimedMessageBox *t = new TimedMessageBox(this,tr("Proceso registrado"));
    accept();
}
