#ifndef ELIMINARCIUDAD_H
#define ELIMINARCIUDAD_H

#include <QDialog>

namespace Ui {
class eliminarciudad;
}

class eliminarciudad : public QDialog
{
    Q_OBJECT

public:
    explicit eliminarciudad(QWidget *parent = nullptr);
    ~eliminarciudad();

signals:
    void ciudadEliminada(QString nombre);

private slots:
    void on_button_Aceptar_clicked();  // Slot del botón aceptar

private:
    Ui::eliminarciudad *ui;
};

#endif // ELIMINARCIUDAD_H
