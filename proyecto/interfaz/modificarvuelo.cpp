#include "modificarvuelo.h"
#include "ui_modificarvuelo.h"
#include <QMessageBox>

ModificarVuelo::ModificarVuelo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModificarVuelo)
{
    ui->setupUi(this);
}

ModificarVuelo::~ModificarVuelo()
{
    delete ui;
}

void ModificarVuelo::setCiudades(const QString &origen, const QString &destino)
{
    // Supongamos que en el diálogo tienes dos QLabel para mostrar el origen y destino.
    ui->labelOrigen->setText(origen);
    ui->labelDestino->setText(destino);
}

void ModificarVuelo::on_button_Aceptar_clicked()
{
    QString origen = ui->labelOrigen->text();
    QString destino = ui->labelDestino->text();
    double nuevoPeso = ui->lineEditPeso->text().toDouble();

    if(nuevoPeso <= 0) {
        QMessageBox::warning(this, "Error", "Ingrese un peso válido.");
        return;
    }

    emit vueloModificado(origen, destino, nuevoPeso);
    accept();
}
