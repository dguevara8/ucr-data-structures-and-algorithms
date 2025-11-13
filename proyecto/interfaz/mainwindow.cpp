#include "../file_manager.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "agregarciudad.h"
#include "modificarvuelo.h"
#include "agregarvuelo.h"
#include "eliminarciudad.h"
#include "eliminarvuelo.h"
#include <QMouseEvent>
#include <QTransform>
#include <QDir>
#include <QDebug>
#include <QCoreApplication>
#include <QAbstractItemView>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->image->installEventFilter(this);
    this->setStyleSheet("QMainWindow { background-color:rgb(255, 255, 255); }");
    this->setFixedSize(ui->image->width() + 10, ui->image->height() + 200);


    // Lista de estados de EE. UU.
    QStringList estados = {
        "Alabama", "Alaska", "Arizona", "Arkansas", "California",
        "Colorado", "Connecticut", "Florida"
    };

    // Agregar los estados al combo box
    ui->comboBox->addItems(estados);
    ui->comboBox_2->addItems(estados);
    ui->label->setStyleSheet("font-size: 11pt;");
    ui->label_2->setStyleSheet("font-size: 11pt;");
    QFont font("Helvetica", 11);
    qApp->setFont(font);
    qApp->setStyleSheet(
        "QPushButton {"
        "   background-color: #3498db;"
        "   color: white;"
        "   border: none;"
        "   border-radius: 5px;"
        "   font-size: 12pt;"
        "}"
        "QPushButton:hover {"
        "   background-color: #2980b9;"
        "}"
    );

    ui->comboBox->setStyleSheet(
        "QComboBox {"
        "    background-color: #ffffff;"
        "    border: 2px solid #2980b9;"
        "    border-radius: 4px;"
        "    padding: 2px;"
        "    font: 12pt 'Helvetica';"
        "    color: #222;"
        "}"
        "QComboBox:hover {"
        "    background-color: #f0f0f0"  // Fondo al pasar el cursor sobre el combo
        "}"
        "QComboBox::drop-down {"
        "    subcontrol-origin: padding;"
        "    subcontrol-position: top right;"
        "    width: 30px;"
        "    border-left: 2px solid #2980b9;"
        "}"
    );
    
    ui->comboBox_2->setStyleSheet(
        "QComboBox {"
        "    background-color: #ffffff;"
        "    border: 2px solid #2980b9;"
        "    border-radius: 4px;"
        "    padding: 2px;"
        "    font: 12pt 'Helvetica';"
        "    color: #222;"
        "}"
        "QComboBox:hover {"
        "    background-color: #f0f0f0"  // Fondo al pasar el cursor sobre el combo
        "}"
        "QComboBox::drop-down {"
        "    subcontrol-origin: padding;"
        "    subcontrol-position: top right;"
        "    width: 30px;"
        "    border-left: 2px solid #2980b9;"
        "}"
    );

        // Construir la ruta correcta a la imagen basada en la ubicación del ejecutable
    QString imagePath = QDir(QCoreApplication::applicationDirPath()).filePath("../src/vuelos/usamap.jpg");

    // Verificar si la imagen existe antes de intentar cargarla
    if (!QFile::exists(imagePath)) {
        qDebug() << "Error: No se encuentra la imagen en:" << imagePath;
    } else {
        if (!originalPix.load(imagePath)) {
            qDebug() << "Error: No se pudo cargar la imagen.";
        } else {
            qDebug() << "Imagen cargada correctamente desde:" << imagePath;
            ui->image->setPixmap(originalPix.scaled(ui->image->size(), Qt::KeepAspectRatio));
        }
    }
    
    ui->image->setPixmap(originalPix);

    // Inicializar las coordenadas de las ciudades
    // Estas son coordenadas aproximadas
    cities["Alabama"] = CityInfo{"Alabama", QPoint(1632, 1118)};
    cities["Alaska"] = CityInfo{"Alaska", QPoint(292, 1288)};
    cities["Arizona"] = CityInfo{"Arizona", QPoint(502, 1112)};
    cities["Arkansas"] = CityInfo{"Arkansas", QPoint(1350, 1084)};
    cities["California"] = CityInfo{"California", QPoint(134, 730)};
    cities["Colorado"] = CityInfo{"Colorado", QPoint(714, 728)};
    cities["Connecticut"] = CityInfo{"Connecticut", QPoint(2152, 558)};
    cities["Florida"] = CityInfo{"Florida", QPoint(1882, 1322)};



    // Agregar ciudades con coordenadas (x, y)
    grafo.agregarCiudad("Alabama", 1632, 1118);
    grafo.agregarCiudad("Alaska", 292, 1288);
    grafo.agregarCiudad("Arizona", 502, 1112);
    grafo.agregarCiudad("Arkansas", 1350, 1084);
    grafo.agregarCiudad("California", 134, 730);
    grafo.agregarCiudad("Colorado", 714, 728);
    grafo.agregarCiudad("Connecticut", 2152, 558);
    grafo.agregarCiudad("Florida", 1882, 1322);


    // Agregar conexiones entre ciudades con su distancia
    grafo.agregarConexion("Florida", "Alaska", 90);
    grafo.agregarConexion("Arizona", "California", 15);
    grafo.agregarConexion("Alabama", "Colorado", 40);
    grafo.agregarConexion("Arkansas", "Florida", 30);
    grafo.agregarConexion("Connecticut", "California", 95);

    // Conectar los eventos de cambio en los combobox
    connect(ui->comboBox, &QComboBox::currentTextChanged, this, &MainWindow::button_calcularRutaOptima);
    connect(ui->comboBox_2, &QComboBox::currentTextChanged, this, &MainWindow::button_calcularRutaOptima);
    connect(ui->button_calcularRutaOptima, &QPushButton::clicked, this, &MainWindow::button_calcularRutaOptima);

}

void MainWindow::button_calcularRutaOptima()
{
    QString origen = ui->comboBox->currentText();
    QString destino = ui->comboBox_2->currentText();

    // Verificar que ambos nodos existan en el grafo
    if (!grafo.obtenerCiudades().count(origen.toStdString()) ||
        !grafo.obtenerCiudades().count(destino.toStdString()))
    {
         ui->statusbar->showMessage("Error: La ciudad de origen o destino no existe en el grafo.");
         return;
    }

    try {
        vector<string> ruta = dijkstra(grafo, origen.toStdString(), destino.toStdString());

        if (ruta.empty()) {
            ui->statusbar->showMessage("No se encontró una ruta entre " + origen + " y " + destino);
            return;
        }

        QVector<QString> rutaQt;
        for (const auto &ciudad : ruta) {
            rutaQt.append(QString::fromStdString(ciudad));
        }
        
        // Mostrar la ruta en la status bar
        QString rutaStr = QStringList(rutaQt.begin(), rutaQt.end()).join(" -> ");
        ui->statusbar->showMessage("Ruta óptima: " + rutaStr);
        
        // Dibujar la ruta en el mapa
        updateMapDisplay(rutaQt);
    } catch (const std::exception &e) {
        ui->statusbar->showMessage("Error al calcular la ruta: " + QString(e.what()));
    }
}


void MainWindow::on_button_AgregarCiudad_clicked()
{
    selectingCityLocation = true;
    ui->statusbar->showMessage("Seleccione la ubicación en el mapa para la nueva ciudad.");
}



void MainWindow::updateMapDisplay(QVector<QString> ruta)
{
    QPixmap mapaActualizado = originalPix.copy();
    QPainter painter(&mapaActualizado);
    painter.setRenderHint(QPainter::Antialiasing);
    QFont font = painter.font();
    font.setPointSize(20);
    painter.setFont(font);

    // Lista de ciudades originales
    QStringList ciudadesOriginales = {
        "Alabama", "Alaska", "Arizona", "Arkansas", "California",
        "Colorado", "Connecticut", "Delaware", "Florida", "Georgia",
        "Hawaii", "Idaho", "Illinois"
    };

    // Dibujar todas las ciudades primero
    for (const auto& ciudad : cities.keys()) {
        QPoint pos = cities[ciudad].coordinates;

        painter.setBrush(QBrush(Qt::red));
        painter.setPen(Qt::black);
        painter.drawEllipse(pos, 17, 17);
        painter.drawText(pos.x() + 10, pos.y() + 5, ciudad);
    }

    // Dibujar conexiones conocidas manualmente
    // Este es un workaround ya que no podemos obtener todas las conexiones del grafo
    painter.setPen(QPen(Qt::darkGray, 2, Qt::DashLine));

    // Lista de conexiones conocidas
    // Puedes añadir más conexiones a esta lista conforme se vayan agregando al grafo
    struct ConexionInfo {
        QString origen;
        QString destino;
        double peso;
    };

    QVector<ConexionInfo> conexiones;  // QVector vacío


    for (const auto& conexion : conexiones) {
        if (cities.contains(conexion.origen) && cities.contains(conexion.destino)) {
            QPoint p1 = cities[conexion.origen].coordinates;
            QPoint p2 = cities[conexion.destino].coordinates;
            painter.drawLine(p1, p2);

            // Dibujar el peso de la conexión
            QPoint midPoint((p1.x() + p2.x()) / 2, (p1.y() + p2.y()) / 2);
            painter.drawText(midPoint, QString::number(conexion.peso));
        }
    }

    // Dibujar la ruta calculada (si hay)
    if (!ruta.isEmpty()) {
        painter.setPen(QPen(Qt::blue, 3, Qt::SolidLine));
        for (int i = 0; i < ruta.size() - 1; i++) {
            QPoint p1 = cities[ruta[i]].coordinates;
            QPoint p2 = cities[ruta[i + 1]].coordinates;
            painter.drawLine(p1, p2);
        }
    }

    ui->image->setPixmap(mapaActualizado.scaled(ui->image->size(), Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::agregarCiudadDesdeVentana(QString nombre, int x, int y)
{
    if (grafo.agregarCiudad(nombre.toStdString(), x, y)) {
        // Agregar a los ComboBox
        ui->comboBox->addItem(nombre);
        ui->comboBox_2->addItem(nombre);
        
        // Agregar la ciudad al mapa interno
        cities[nombre] = CityInfo{nombre, QPoint(x, y)};
        
        // Redibujar el mapa (asegúrate de escalar la imagen)
        updateMapDisplay(QVector<QString>());
        
        ui->statusbar->showMessage("Ciudad agregada exitosamente.");
    } else {
        ui->statusbar->showMessage("Error: La ciudad ya existe.");
    }
}

void MainWindow::on_button_AgregarConexion_clicked()
{
    // Obtener las ciudades seleccionadas en los combobox
    QString origen = ui->comboBox->currentText();
    QString destino = ui->comboBox_2->currentText();

    // Verificar que no se está intentando conectar una ciudad consigo misma
    if (origen == destino) {
        ui->statusbar->showMessage("Error: No se puede conectar una ciudad consigo misma.");
        return;
    }

    // Abrir ventana para especificar el peso/distancia
    agregarvuelo *ventana3 = new agregarvuelo(this);

    // Pasar las ciudades seleccionadas a la ventana
    ventana3->setCiudades(origen, destino);

    // Conectar la señal que se emitirá cuando se agregue la conexión
    connect(ventana3, &agregarvuelo::conexionAgregada, this, &MainWindow::agregarConexionDesdeVentana3);

    ventana3->exec(); // Mostrar la ventana de forma modal
}

void MainWindow::agregarConexionDesdeVentana3(QString origen, QString destino, double peso)
{
    // Intentar agregar la conexión al grafo
    if (grafo.agregarConexion(origen.toStdString(), destino.toStdString(), peso)) {
        ui->statusbar->showMessage("Conexión agregada correctamente: " + origen + " -> " + destino);

        // Crear una copia del mapa original
        QPixmap mapaActualizado = originalPix.copy();
        QPainter painter(&mapaActualizado);
        painter.setRenderHint(QPainter::Antialiasing);

        // Dibujar todas las ciudades primero
        QStringList ciudadesOriginales = {
            "Alabama", "Alaska", "Arizona", "Arkansas", "California",
            "Colorado", "Connecticut", "Delaware", "Florida", "Georgia",
            "Hawaii", "Idaho", "Illinois"
        };

        // Dibujar todas las ciudades
        for (const auto& ciudad : cities.keys()) {
            QPoint pos = cities[ciudad].coordinates;

            // Si es una ciudad original, dibujarla en rojo
            if (ciudadesOriginales.contains(ciudad)) {
                painter.setBrush(QBrush(Qt::red));
            }
            // Si es una ciudad agregada posteriormente, dibujarla en verde
            else {
                painter.setBrush(QBrush(Qt::green));
            }
            QFont font = painter.font();
            font.setPointSize(20);
            painter.setFont(font);
            painter.setPen(Qt::black);
            painter.drawEllipse(pos, 17, 17);
            painter.drawText(pos.x() + 10, pos.y() + 5, ciudad);
        }

        // Dibujar solo la nueva conexión
        if (cities.contains(origen) && cities.contains(destino)) {
            painter.setPen(QPen(Qt::blue, 3, Qt::SolidLine));
            QPoint p1 = cities[origen].coordinates;
            QPoint p2 = cities[destino].coordinates;
            painter.drawLine(p1, p2);

            // Dibujar el peso de la conexión
            QPoint midPoint((p1.x() + p2.x()) / 2, (p1.y() + p2.y()) / 2);
            painter.drawText(midPoint, QString::number(peso));
        }

        ui->image->setPixmap(mapaActualizado.scaled(ui->image->size(), Qt::KeepAspectRatio));
    } else {
        ui->statusbar->showMessage("Error: No se pudo agregar la conexión.");
    }
}


void MainWindow::on_button_EliminarCiudad_clicked()
{
    eliminarciudad *ventana4 = new eliminarciudad(this);
    connect(ventana4, &eliminarciudad::ciudadEliminada, this, &MainWindow::eliminarCiudadDesdeVentana4);
    ventana4->exec();
}

void MainWindow::eliminarCiudadDesdeVentana4(QString nombre)
{
    // Intentar eliminar la ciudad del grafo
    if (grafo.eliminarCiudad(nombre.toStdString())) {
        // Remover la ciudad del mapa cities de MainWindow
        if (cities.contains(nombre)) {
            cities.remove(nombre);
        }

        // Remover la ciudad de los ComboBox
        int index1 = ui->comboBox->findText(nombre);
        if (index1 != -1) ui->comboBox->removeItem(index1);

        int index2 = ui->comboBox_2->findText(nombre);
        if (index2 != -1) ui->comboBox_2->removeItem(index2);

        // Redibujar el mapa sin la ciudad eliminada
        updateMapDisplay(QVector<QString>());

        ui->statusbar->showMessage("Ciudad eliminada exitosamente.");
    } else {
        ui->statusbar->showMessage("Error: La ciudad no existe.");
    }
}

void MainWindow::on_button_EliminarVuelo_clicked()
{
    EliminarVuelo *ventana5 = new EliminarVuelo(this, getGraph());

    // Conectar la señal con la función para eliminar la conexión
    connect(ventana5, &EliminarVuelo::vueloEliminado, this, &MainWindow::eliminarConexionDesdeVentana5);

    ventana5->exec(); // Mostrar la ventana de forma modal
}

void MainWindow::eliminarConexionDesdeVentana5(QString origen, QString destino)
{
    if (grafo.eliminarConexion(origen.toStdString(), destino.toStdString())) {
        ui->statusbar->showMessage("Vuelo eliminado: " + origen + " -> " + destino);

        // Redibujar el mapa sin la conexión eliminada
        updateMapDisplay(QVector<QString>());

    } else {
        ui->statusbar->showMessage("Error: No se pudo eliminar la conexión.");
    }
}

void MainWindow::on_button_ModificarVuelo_clicked()
{
    // Usamos las ciudades actualmente seleccionadas en los comboBox
    QString origen = ui->comboBox->currentText();
    QString destino = ui->comboBox_2->currentText();

    if (origen == destino) {
        ui->statusbar->showMessage("Error: Seleccione dos ciudades distintas para modificar la conexión.");
        return;
    }

    // Abrir el diálogo para modificar el vuelo
    ModificarVuelo *dialog = new ModificarVuelo(this);
    dialog->setCiudades(origen, destino);

    // Conectar la señal del diálogo con nuestro slot que modifica la conexión
    connect(dialog, &ModificarVuelo::vueloModificado, this, &MainWindow::modificarConexionDesdeVentana);
    
    dialog->exec();
}

void MainWindow::modificarConexionDesdeVentana(QString origen, QString destino, double nuevoPeso)
{
    if (grafo.modificarConexion(origen.toStdString(), destino.toStdString(), nuevoPeso)) {
        ui->statusbar->showMessage("Conexión modificada: " + origen + " -> " + destino + " Nuevo peso: " + QString::number(nuevoPeso));
        updateMapDisplay(QVector<QString>());
    } else {
        ui->statusbar->showMessage("Error: No se pudo modificar la conexión de " + origen + " a " + destino);
    }
}




bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (selectingCityLocation && obj == ui->image && event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        QPoint widgetClick = mouseEvent->pos();

        // Tamaño del widget donde se muestra la imagen
        QSize widgetSize = ui->image->size();
        // Se escala el QPixmap original al tamaño del widget conservando el aspecto
        QPixmap scaledPixmap = originalPix.scaled(widgetSize, Qt::KeepAspectRatio);
        QSize scaledSize = scaledPixmap.size();

        // Calcular el offset (la imagen escalada suele estar centrada en el widget)
        int offsetX = (widgetSize.width() - scaledSize.width()) / 2;
        int offsetY = (widgetSize.height() - scaledSize.height()) / 2;

        // Calcular la posición relativa dentro de la imagen escalada
        QPoint relativePos = widgetClick - QPoint(offsetX, offsetY);

        // Verificar que el clic se haya realizado dentro del área de la imagen
        if (relativePos.x() < 0 || relativePos.y() < 0 ||
            relativePos.x() > scaledSize.width() || relativePos.y() > scaledSize.height())
        {
            ui->statusbar->showMessage("Click fuera del mapa.");
            return true;
        }

        // Convertir la posición relativa al sistema de coordenadas del QPixmap original
        double factorX = double(originalPix.width()) / double(scaledSize.width());
        double factorY = double(originalPix.height()) / double(scaledSize.height());
        QPoint originalPos(relativePos.x() * factorX, relativePos.y() * factorY);

        // Termina el modo de selección
        selectingCityLocation = false;

        // Abrir el diálogo de AgregarCiudad con las coordenadas convertidas
        AgregarCiudad *dialog = new AgregarCiudad(this);
        dialog->setCoordinates(originalPos);

        // Conectar la señal para agregar la ciudad
        connect(dialog, &AgregarCiudad::ciudadAgregada, this, &MainWindow::agregarCiudadDesdeVentana);

        if (dialog->exec() == QDialog::Accepted) {
            // Se agregará la ciudad en agregarCiudadDesdeVentana
        }
        return true;
    }
    return QMainWindow::eventFilter(obj, event);
}

void MainWindow::on_button_GuardarGrafo_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Guardar Grafo"), "", tr("Text Files (*.txt)"));
    if (fileName.isEmpty())
        return;
        
    // Convertir a std::string y guardar
    if (guardarGrafo(grafo, fileName.toStdString())) {
        ui->statusbar->showMessage("Grafo guardado exitosamente en: " + fileName);
    } else {
        ui->statusbar->showMessage("Error al guardar el grafo.");
    }
}

void MainWindow::on_button_CargarGrafo_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Cargar Grafo"), "", tr("Text Files (*.txt)"));
    if (fileName.isEmpty())
        return;
    
    if (!cargarGrafo(grafo, fileName.toStdString())) {
        ui->statusbar->showMessage("Error al cargar el grafo desde: " + fileName);
        return;
    }
    
    // Desconectar señales para evitar disparos automáticos mientras se repuebla
    disconnect(ui->comboBox, &QComboBox::currentTextChanged, this, &MainWindow::button_calcularRutaOptima);
    disconnect(ui->comboBox_2, &QComboBox::currentTextChanged, this, &MainWindow::button_calcularRutaOptima);
    
    // Limpiar ComboBoxes y la estructura local de ciudades
    cities.clear();
    ui->comboBox->clear();
    ui->comboBox_2->clear();
    
    // Repoblar los ComboBoxes a partir de las ciudades en el grafo
    auto ciudadesMap = grafo.obtenerCiudades();
    for (const auto &par : ciudadesMap) {
        const auto &ciudad = par.second;
        QString nombre = QString::fromStdString(ciudad.nombre);
        cities[nombre] = CityInfo{nombre, QPoint(ciudad.x, ciudad.y)};
        ui->comboBox->addItem(nombre);
        ui->comboBox_2->addItem(nombre);
    }
    
    // Establecer un valor predeterminado (si hay ciudades)
    if(ui->comboBox->count() > 0) {
         ui->comboBox->setCurrentIndex(0);
         ui->comboBox_2->setCurrentIndex(0);
    }
    
    // Volver a conectar las señales
    connect(ui->comboBox, &QComboBox::currentTextChanged, this, &MainWindow::button_calcularRutaOptima);
    connect(ui->comboBox_2, &QComboBox::currentTextChanged, this, &MainWindow::button_calcularRutaOptima);
    
    // Actualiza el mapa para reflejar la información cargada
    updateMapDisplay(QVector<QString>());
    ui->statusbar->showMessage("Grafo cargado exitosamente desde: " + fileName);
}