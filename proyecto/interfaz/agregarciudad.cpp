#include "agregarciudad.h"
#include "ui_agregarciudad.h"
#include <QMessageBox>

AgregarCiudad::AgregarCiudad(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AgregarCiudad)
{
    ui->setupUi(this);
}

AgregarCiudad::~AgregarCiudad()
{
    delete ui;
}

void AgregarCiudad::on_button_Aceptar_clicked()
{
    QString nombre = ui->lineEditCiudad->text();
    if (nombre.isEmpty()) {
        QMessageBox::warning(this, "Error", "Ingrese el nombre de la ciudad.");
        return;
    }
    int x = selectedCoordinates.x();
    int y = selectedCoordinates.y();
    
    emit ciudadAgregada(nombre, x, y);
    accept();
}


void AgregarCiudad::setCoordinates(const QPoint &point)
{
    selectedCoordinates = point;
    // Mostrar las coordenadas en los QLineEdit y hacerlos de solo lectura
    ui->lineEditCiudadX->setText(QString::number(point.x()));
    ui->lineEditCiudadY->setText(QString::number(point.y()));
    ui->lineEditCiudadX->setReadOnly(true);
    ui->lineEditCiudadY->setReadOnly(true);
}