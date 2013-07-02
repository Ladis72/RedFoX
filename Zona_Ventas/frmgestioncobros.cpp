#include "frmgestioncobros.h"
#include "ui_frmgestioncobros.h"

frmGestionCobros::frmGestionCobros(QWidget *parent) :
    MayaModule(module_zone(),module_name(),parent),
    ui(new Ui::frmGestionCobros),
    toolButton(tr("Gest. Cobros"),":/Icons/PNG/Cobros.png",this),
    menuButton(QIcon(":/Icons/PNG/Cobros.png"),tr("Gest. Cobros"),this)
{
    ui->setupUi(this);
    ui->txtfecha_ini->setDate(QDate::currentDate());
    ui->txtfecha_fin->setDate(QDate::currentDate().addDays(7));
    ui->txtbuscar_cliente->setText("a");
    QSqlQueryModel *modelo_clientes = new QSqlQueryModel(this);
    modelo_clientes->setQuery("select id,codigo_cliente, nombre_fiscal, cif_nif from clientes where nombre_fiscal like '%a' limit 0,150",
                              QSqlDatabase::database("Maya"));

    ui->tabla_clientes->setModel(modelo_clientes);
    ui->tabla_clientes->setColumnHidden(0,true);
    ui->tabla_clientes->setColumnWidth(1,70);
    ui->tabla_clientes->setColumnWidth(2,170);
    ui->tabla_clientes->setColumnWidth(3,90);
    modelo_clientes->setHeaderData(1,Qt::Horizontal,tr("Código"));
    modelo_clientes->setHeaderData(2,Qt::Horizontal,tr("Denominación"));
    modelo_clientes->setHeaderData(3,Qt::Horizontal,tr("Cif/Nif"));
    ui->txtbuscar_cliente->setFocus();

}

frmGestionCobros::~frmGestionCobros()
{
    delete ui;
}


void frmGestionCobros::on_txtbuscar_cliente_textChanged(const QString &arg1)
{
    QSqlQueryModel *modelo_clientes = new QSqlQueryModel(this);
    QString indice,cSQL;
    if(ui->radNombre->isChecked())
        indice = "nombre_fiscal";
    if(ui->radCif->isChecked())
        indice = "cif_nif";
    if(ui->radCodigo->isChecked())
        indice = "cif_nif";
    if (ui->radEmpieza->isChecked())
    {
        cSQL = "select id,codigo_cliente, nombre_fiscal, cif_nif from clientes where "+indice+
                " like '"+arg1.trimmed()+"%'";
        modelo_clientes->setQuery(cSQL,QSqlDatabase::database("Maya"));
    } else {
        cSQL= "select id,codigo_cliente, nombre_fiscal, cif_nif from clientes where "+indice+
                                          " like '%"+arg1.trimmed()+"%'";
        modelo_clientes->setQuery(cSQL,QSqlDatabase::database("Maya"));
    }

    ui->tabla_clientes->setModel(modelo_clientes);
    ui->tabla_clientes->setColumnHidden(0,true);
    ui->tabla_clientes->setColumnWidth(1,70);
    ui->tabla_clientes->setColumnWidth(2,170);
    ui->tabla_clientes->setColumnWidth(3,90);
    modelo_clientes->setHeaderData(1,Qt::Horizontal,tr("Código"));
    modelo_clientes->setHeaderData(2,Qt::Horizontal,tr("Denominación"));
    modelo_clientes->setHeaderData(3,Qt::Horizontal,tr("Cif/Nif"));


}
