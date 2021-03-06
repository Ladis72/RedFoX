#ifndef FRMALBARAN_H
#define FRMALBARAN_H

#include "../Auxiliares/Globlal_Include.h"
#include "../Auxiliares/table_helper.h"
#include "../mayamodule.h"
#include "../Auxiliares/timedmessagebox.h"
namespace Ui {
class FrmAlbaran;
}

class FrmAlbaran : public MayaModule
{
    Q_OBJECT
    
public:
    explicit FrmAlbaran(QWidget *parent = 0);
    ~FrmAlbaran();
    void LLenarCampos();
    void LLenarCamposCliente();
    void VaciarCampos();
    void BloquearCampos(bool state);
    void DesbloquearCampos();
    void LLenarAlbaran();

    module_zone module_zone(){return Ventas;}
    QString module_name(){return "Albaranes Ventas";}
    QAction * ModuleMenuBarButton(){return &menuButton;}
    QString ModuleMenuPath(){return tr("");}
    
    QPushButton* wantShortCut(bool& ok){ok = true; return push;}
    void setUpBusqueda();
signals:

private slots:
    void on_btnSiguiente_clicked();

    void on_btnAnadir_clicked();

    void on_botBuscarCliente_clicked();

    void on_btnAnterior_clicked();

    void on_btnEditar_clicked();

    void on_btnGuardar_clicked();

    void on_btn_borrar_clicked();

    void totalChanged(double base , double dto ,double subtotal , double iva, double re, double total, QString moneda);
    void desglose1Changed(double base, double iva, double re, double total);
    void desglose2Changed(double base, double iva, double re, double total);
    void desglose3Changed(double base, double iva, double re, double total);
    void desglose4Changed(double base, double iva, double re, double total);

    void lineaReady(lineaDetalle*);
    void lineaDeleted(lineaDetalle*);
    void on_btndeshacer_clicked();

    void on_tabWidget_2_currentChanged(int index);

    void on_btnImprimir_clicked();

    void on_radBusqueda_toggled(bool checked);

    void on_cboOrden_currentIndexChanged(const QString &arg1);

    void on_table2_clicked(const QModelIndex &index);

    void on_table2_doubleClicked(const QModelIndex &index);

    void on_btnBuscar_clicked();

    void on_btnForzar_edicion_clicked();

    void on_btnFacturar_clicked();

    void on_spinporc_Dto_editingFinished();

    void on_spinPorc_dto_pp_editingFinished();

    void mostrarBusqueda();
    void ocultarBusqueda();
    void filter_table(QString texto, QString orden, QString modo);
    void on_table2_row_moved(QModelIndex actual,QModelIndex previous);
    void on_cboseries_currentIndexChanged(const QString &arg1);

private:
    Ui::FrmAlbaran *ui;
    QSqlQueryModel *ModelLin_alb;
    Table_Helper helper;
    bool in_edit;

    QAction menuButton;
    QPushButton* push;
    QSqlQueryModel *m;
    void formato_tabla();

    void calcular_iva_gastos();
    TimedMessageBox *t;
    QSqlQueryModel *series;
    bool eventFilter(QObject *obj, QEvent *event);

    BarraBusqueda* m_busqueda;
    QLabel* lblimpreso;
    QLabel* lblfacturado;
    QComboBox* cboseries;
    QString texto;
    QString orden;
    QString modo;
    QString serie;
};

#endif // FRMALBARAN_H
