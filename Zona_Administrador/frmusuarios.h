#ifndef FRMUSUARIOS_H
#define FRMUSUARIOS_H

#include <QDialog>
#include "auxmodule.h"
#include "../mayamodule.h"
namespace Ui {
class FrmUsuarios;
}

class FrmUsuarios : public MayaModule
{
    Q_OBJECT
    
public:
    explicit FrmUsuarios(QWidget *parent = 0);
    ~FrmUsuarios();
    

    module_zone module_zone(){return AdminZone;}
    QString module_name(){return "Control de usuarios";}
    QAction * ModuleMenuBarButton(){return &menuButton;}
    QString ModuleMenuPath(){return tr("");}
    QPushButton* wantShortCut(bool& ok){ok = false; return 0;}
private slots:
    void crear_User();
    void on_btn_modPass_clicked();
    void on_botBorrar_user_clicked();
    void on_botGuardar_user_clicked();
    void on_botBuscar_user_clicked();
    void on_botAnterior_user_clicked();
    void on_botSiguiente_user_clicked();
    void on_botAnadir_user_clicked();

private:
    Ui::FrmUsuarios *ui;
    void getModulesFromDB();
    void addAdminModule(AuxModule *m);
    void addMantenModule(AuxModule *m);
    void addComprasModule(AuxModule *m);
    void addVentasModule(AuxModule *m);
    void addArchivosModule(AuxModule *m);
    void addAlmacenModule(AuxModule *m);
    void addUtilidadesModule(AuxModule *m);
    void addNoZoneModule(AuxModule *m);
    void addContaModule(AuxModule *m);
    void addSecMedicModule(AuxModule *m);
    void addInfoMedicModule(AuxModule *m);
    void llenar_user(QSqlRecord record);
    void llenarModulos(int id_user);

    QVector<AuxModule*> _modulos;

    QAction menuButton;
};

#endif // FRMUSUARIOS_H
