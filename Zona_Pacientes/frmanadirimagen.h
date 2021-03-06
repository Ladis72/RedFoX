#ifndef FRMANADIRIMAGEN_H
#define FRMANADIRIMAGEN_H

#include "../Auxiliares/Globlal_Include.h"
namespace Ui {
class FrmAnadirImagen;
}

class FrmAnadirImagen : public QDialog
{
    Q_OBJECT
    
public:
    explicit FrmAnadirImagen(QWidget *parent = 0);
    ~FrmAnadirImagen();
public slots:
    void Recuperarid(int cid_episodio);
private:
    Ui::FrmAnadirImagen *ui;
private slots:

    void AnadirImagen();
    void GuardarInfoImagen_en_BD();
    void GuardarDatosEnObjetoImagen();
    void Cambiotipo_imagen(QString);
signals:


};

#endif // FRMANADIRIMAGEN_H
