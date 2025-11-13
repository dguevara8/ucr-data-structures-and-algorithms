#ifndef AGREGARCIUDAD_H
#define AGREGARCIUDAD_H

#include <QDialog>

namespace Ui {
class AgregarCiudad;
}

class AgregarCiudad : public QDialog
{
    Q_OBJECT

public:
    void setCoordinates(const QPoint &point);
    explicit AgregarCiudad(QWidget *parent = nullptr);
    ~AgregarCiudad();

signals:
    void ciudadAgregada(QString nombre, int x, int y);

private slots:
    void on_button_Aceptar_clicked();  // Slot del botón aceptar

private:
    QPoint selectedCoordinates;
    Ui::AgregarCiudad *ui;
};

#endif // AGREGARCIUDAD_H
