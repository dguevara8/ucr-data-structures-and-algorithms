#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../graphs.h"  // Incluye la clase de grafo
#include "../algorithm.cpp"
#include <QMainWindow>
#include <QLabel>
#include <QPixmap>
#include <QPainter>
#include <QMap>
#include <QPoint>
#include <QMouseEvent>
#include <QTransform>

#include "agregarciudad.h"
#include "agregarvuelo.h"
#include "eliminarciudad.h"
#include "eliminarvuelo.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Graph& getGraph() { return grafo; }

// In mainwindow.h
public slots:
    void updateMapDisplay(QVector<QString> ruta); // Called after calculating route

private slots:
    void on_button_GuardarGrafo_clicked();
    void on_button_CargarGrafo_clicked();
    void on_button_ModificarVuelo_clicked();
    void modificarConexionDesdeVentana(QString origen, QString destino, double nuevoPeso);
    void button_calcularRutaOptima(); // Función existente

    void on_button_AgregarCiudad_clicked();
    void agregarCiudadDesdeVentana(QString nombre, int x, int y);     // Para agregar nuevas ciudades
    void on_button_AgregarConexion_clicked();
    void agregarConexionDesdeVentana3(QString origen, QString destino, double peso);
    void on_button_EliminarCiudad_clicked();
    void eliminarCiudadDesdeVentana4(QString nombre);
    void on_button_EliminarVuelo_clicked();
    void eliminarConexionDesdeVentana5(QString origen, QString destino);

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

private:
    Ui::MainWindow *ui;
    QPixmap originalPix; // Variable existente
    bool selectingCityLocation = false;

    Graph grafo;  // Grafo que almacena las conexiones entre ciudades

    // Estructura para almacenar información de ciudades
    struct CityInfo {
        QString name;
        QPoint coordinates; // Coordenadas en el mapa
    };

    QMap<QString, CityInfo> cities; // Mapa para almacenar información de ciudadess

};

#endif // MAINWINDOW_H
