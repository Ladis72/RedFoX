#ifndef DB_CONSULTA_VIEW_H
#define DB_CONSULTA_VIEW_H

#include <QDialog>
#include "../Auxiliares/Globlal_Include.h"

namespace Ui {
class db_consulta_view;
}

class db_consulta_view : public QDialog
{
    Q_OBJECT
    
public:
    explicit db_consulta_view(QWidget *parent = 0);
    ~db_consulta_view();
    void set_texto_tabla(QString tabla);
    void set_SQL(QString cSQL);
    void set_filtro(QString filtro);
    void set_titulo(QString titulo);
    void set_headers(QStringList cabecera);
    void set_tamano_columnas(QVariantList tamanos);
    void set_delegate_monetary(QVariantList cols);
    void set_delegate_fecha(QVariantList cols);
    void set_campoBusqueda(QStringList campos);
    void set_db(QString nombre_db);
    int get_id() {return this->id;}
    
    int getId_tarifa_cliente() const;
    void setId_tarifa_cliente(int value);

    int getTipo_dto_tarifa() const;
    void setTipo_dto_tarifa(int value);

private:
    Ui::db_consulta_view *ui;
    QString cSQL;
    QStringList campoBusqueda;
    QString filtro;
    QString cSQLFiltered;
    QStringList headers;
    QString db;
    QString tabla;
    int id;
    QSqlQueryModel *modelo;
    int id_tarifa_cliente;
    int tipo_dto_tarifa;

private slots:
    bool eventFilter(QObject *target, QEvent *event);

    void on_lineaTextoBuscar_textChanged(const QString &arg1);
    void on_resultado_list_clicked(const QModelIndex &index);
    void on_resultado_list_doubleClicked(const QModelIndex &index);
};

#endif // DB_CONSULTA_VIEW_H
