#ifndef DIVISIONALMACENEXT_H
#define DIVISIONALMACENEXT_H

#include <QObject>
#include "../moduleextension.h"
class DivisionAlmacenExt : public ModuleExtension
{
    Q_OBJECT
public:
    explicit DivisionAlmacenExt(QObject *parent = 0);
    
    QList<QAction *> Extensions();
    QString ExtensionPath(){return "Divisiones de Almacén";}// Use '|' to subPaths

    MayaModule::module_zone module_zone(){return MayaModule::Almacen;}
signals:
    
public slots:
private slots:
    void handle_actions();
private:
    QAction Seccion;
    QAction familias;
    QAction subFam;
    QAction subsubFam;
    QAction grupos;
    QVector<QPair<QAction *, MayaModule::accessLevel> > _actions;
};

#endif // DIVISIONALMACENEXT_H
