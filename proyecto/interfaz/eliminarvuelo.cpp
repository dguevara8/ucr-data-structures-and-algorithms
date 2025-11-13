#include "eliminarvuelo.h"
#include "ui_eliminarvuelo.h"
#include "../graphs.h"

EliminarVuelo::EliminarVuelo(QWidget *parent, Graph &graphRef) :
    QDialog(parent),
    ui(new Ui::EliminarVuelo),
    graph(graphRef)
{
    ui->setupUi(this);

    // Poblar los ComboBox con las ciudades disponibles
   // Suponiendo que `MainWindow` tiene una referencia global `grafo`
   for (const auto& pair : graph.obtenerCiudades()) {
       ui->comboBox_Origen->addItem(QString::fromStdString(pair.first));
   }

   connect(ui->comboBox_Origen, &QComboBox::currentTextChanged, this, [=](const QString &origen) {
       ui->comboBox_Destino->clear();
       if (graph.obtenerCiudades().count(origen.toStdString())) {
           for (const auto& vuelo : graph.obtenerCiudades().at(origen.toStdString()).conexiones) {
               ui->comboBox_Destino->addItem(QString::fromStdString(vuelo.destino));
           }
       }
   });
}

EliminarVuelo::~EliminarVuelo()
{
   delete ui;
}

void EliminarVuelo::on_button_Eliminar_clicked()
{
   QString origen = ui->comboBox_Origen->currentText();
   QString destino = ui->comboBox_Destino->currentText();

   if (!origen.isEmpty() && !destino.isEmpty()) {
       emit vueloEliminado(origen, destino);
       accept(); // Cerrar la ventana
   } else {
       ui->statusLabel->setText("Error: Debes seleccionar ambas ciudades.");
   }
}
