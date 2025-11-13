#include "agregarvuelo.h"
#include "ui_agregarvuelo.h"

agregarvuelo::agregarvuelo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::agregarvuelo)
{
    ui->setupUi(this);
}

agregarvuelo::~agregarvuelo()
{
    delete ui;
}

void agregarvuelo::setCiudades(const QString &origen, const QString &destino)
{
    ciudadOrigen = origen;
    ciudadDestino = destino;

    // Actualizar etiquetas en la interfaz
    ui->labelOrigen->setText("Origen: " + origen);
    ui->labelDestino->setText("Destino: " + destino);
}

void agregarvuelo::on_buttonBox_accepted()
{
    // Obtener el peso/distancia del spinBox
    double peso = ui->spinBoxPeso->value();

    // Emitir la señal con los datos
    emit conexionAgregada(ciudadOrigen, ciudadDestino, peso);
}
