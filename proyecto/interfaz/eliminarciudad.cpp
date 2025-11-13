#include "eliminarciudad.h"
#include "ui_eliminarciudad.h"

eliminarciudad::eliminarciudad(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::eliminarciudad)
{
    ui->setupUi(this);
}

eliminarciudad::~eliminarciudad()
{
    delete ui;
}

void eliminarciudad::on_button_Aceptar_clicked()
{
    QString nombre = ui->lineEditCiudad2->text();
    emit ciudadEliminada(nombre);
    close();
}
