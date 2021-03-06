#ifndef FRMEMPRESAS_H
#define FRMEMPRESAS_H

#include "../Auxiliares/Globlal_Include.h"
#include "auxmodule.h"
#include "../empresa.h"
#include "../mayamodule.h"
#include "copy_db_progressfrm.h"



namespace Ui {
class FrmEmpresas;
}

class FrmEmpresas : public MayaModule
{
    Q_OBJECT
    
public:
    explicit FrmEmpresas(QWidget *parent = 0);
    ~FrmEmpresas();
    void LLenarCampos();
    void CargarCamposEnEmpresa();

    module_zone module_zone(){return AdminZone;}
    QString module_name(){return "Control de empresas";}
    QAction * ModuleMenuBarButton(){return &menuButton;}
    QString ModuleMenuPath(){return tr("");}
    QPushButton* wantShortCut(bool& ok){ok = false; return 0;}


private slots:
    //TODO - boton buscar
    //TODO - boton borrar

    void txtpoblacion_editingFinished();

    void txtcp_editingFinished();

    void on_btn_ruta_db_clicked();

    void on_txtcDriver_currentIndexChanged(int index);

    void on_btn_migrar_clicked();

    void on_addGrupo_clicked();

    void on_btnAddEmpresa_clicked();

    void on_treeEmpresas_itemSelectionChanged();

    void on_btnEditar_clicked();

    void on_btnConfigTerminal_clicked();

private:
    Ui::FrmEmpresas *ui;
    Empresa oEmpresa;

    void limpiar_campos();
    bool crear_empresa_sqlite(copy_db_progressFrm * form);
    bool crear_medica_sqlite(copy_db_progressFrm * form);
    bool crear_empresa_mysql(copy_db_progressFrm * form);
    bool crear_medica_mysql(copy_db_progressFrm * form);

    QAction menuButton;

    struct empresa
    {
        QString name;
        QSqlRecord record;
    };

    QHash<QString, QPair<QList<empresa> , QSqlRecord> > _empresas;
    void showEmpresas();
    void getEmpresas();
    void _addEmpresa();
    void _llenarCampos(QSqlRecord r);

    void blockGUI(bool block, bool limpia);
};

#endif // FRMEMPRESAS_H
