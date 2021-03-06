#ifndef FRMFICHAPACIENTE_H
#define FRMFICHAPACIENTE_H

#include "../Auxiliares/Globlal_Include.h"

#include "paciente.h"
#include "episodio.h"
#include "visitas.h"
#include "imagenesdiagnostico.h"

namespace Ui {
class FrmFichaPaciente;
}

class FrmFichaPaciente : public QDialog
{
    Q_OBJECT
    
public:
    explicit FrmFichaPaciente(QWidget *parent = 0);
    ~FrmFichaPaciente();
    void cargarDatos(int id_cliente);
    void cargarEpisodio(int control);
    void guardarDatosPaciente();
    Paciente *oPaciente;
    Episodio *oEpisodio;
    Visitas *oVisita;

    ImagenesDiagnostico *oImagenes;
public slots:
    void AnadirDatosMedicamento(int id, QString nombre,QString codigo_nacional);
    void cargarDatosMedicamento(int, int);
    void cargarDatosImagenes(int,int);
    void guardarDatosImagenes();
    void deshacerDatosImagenes();
    void recibedatospaciente(int,QString);
private slots:
    void finishedSlot(QNetworkReply* reply);
    void on_btnAnadirEpisodio_clicked();
    void ListaEpisodio_clicked(QModelIndex index);
    void on_btnBuscarCIEEpisodio_clicked();
    void on_btnEditarPaciente_clicked();
    void on_btnGuardarPaciente_clicked();
    void on_btnGuardarEpisodio_clicked();
    void on_btnEditarEpisodio_clicked();
    void on_btnDeshacerEpisodio_clicked();
    void on_btnAnadirFarma_clicked();
    void on_btnAnadirHerb_clicked();
    void BuscarCIE();
    void RecuperarCIE(int,QString,QString);
    void ActivarControlesFarmacologia();
    void GuardarDatosFarmacologia();
    void llenartablahistorialfarmacologiaepisodio();
    void llenartablahistorialimagenesepisodio();
    void llenartablahistorialanalisisepisodio();
    void llenarhistorialvisitas();
    void BorrarDatosMedicamento();
    void MostrarFichaMedicamento();
    void MostrarFichaMedicamento2();
    void AnadirImagenDiagnostico();
    void BorrarImagenDiagnostico();
    void EditarImagenDiagnostico();
    void AnadirInterconsulta();
    void AnadirAnalitica();
    void BorrarAnalitica();
    void VerAnalitica();
    void on_BtnDeshacerPaciente_clicked();
    void AnadirVisita();
    void ListaVisita_Clicked(QModelIndex index);
    void CargarVisita(int nid);
    void bntEditarVisita_clicked();
    void btnGuardarVisita_clicked();
    void btnDeshacerVisita_clicked();
    void anadirDiagnostico();
    void vademecums();
    void ListaHistorialFarmacologia_clicked(QModelIndex index);
    void ListaHistorialImagenes_clicked(QModelIndex index);
signals:
    void pasaid(int);
    void pasacodigo_nacional(QString);
    void pasaPaciente(QString);

private:
    Ui::FrmFichaPaciente *ui;
    QNetworkAccessManager* nam;
    //QXmlStreamReader *xmlReader;
    QXmlStreamAttributes attrib;
    QSqlQuery paciente;
    void BloquearCamposPaciente(bool state);
    void BloquearCamposEpisodio(bool state);
    void LLenarEpisodio();
    void VaciarCamposEpisodio();
    void VaciarCamposHistoriacompleto();
    void BloquearCamposImagen();
public:
    int id_farmaco;
};

#endif // FRMFICHAPACIENTE_H
