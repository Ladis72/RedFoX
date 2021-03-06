#ifndef CUENTAS_CONTABLES_H
#define CUENTAS_CONTABLES_H

#include <QObject>
#include "../Auxiliares/Globlal_Include.h"

class Cuentas_contables : public QObject
{
    Q_OBJECT
public:
    explicit Cuentas_contables(QObject *parent = 0);

    int id;
    QString codigo_cta;
    QString descripcion;
    bool activo;
    QString codigo_balance;
    QString desglose_balance;
    QString afecta_a;
    double saldo;
    QString cif_nif;
    double saldo_debe;
    double saldo_haber;
    QString direccion;
    QString poblacion;
    QString provincia;
    QString pais;




signals:
    
public slots:
    bool anadir_cuenta();
    void guardar_cuenta();
    void recuperar_cuenta(QString cuenta);
    void recuperar_cuenta(int id);
    QString completar_cuenta(QString cuenta_);
    QString nueva_cuenta();
    void clear();

    
};

#endif // CUENTAS_CONTABLES_H
