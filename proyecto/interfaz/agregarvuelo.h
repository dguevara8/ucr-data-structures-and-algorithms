#ifndef AGREGARVUELO_H
#define AGREGARVUELO_H

#include <QDialog>

namespace Ui {
class agregarvuelo;
}

class agregarvuelo : public QDialog
{
    Q_OBJECT

public:
    explicit agregarvuelo(QWidget *parent = nullptr);
    ~agregarvuelo();

    // Establecer las ciudades seleccionadas
    void setCiudades(const QString &origen, const QString &destino);

signals:
    // Señal que se emitirá cuando se agregue una conexión
    void conexionAgregada(QString origen, QString destino, double peso);

private slots:
    // Slot para el botón de aceptar
    void on_buttonBox_accepted();

private:
    Ui::agregarvuelo *ui;
    QString ciudadOrigen;
    QString ciudadDestino;
};

#endif // AGREGARVUELO_H
