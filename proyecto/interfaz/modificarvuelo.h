#ifndef MODIFICARVUELO_H
#define MODIFICARVUELO_H

#include <QDialog>

namespace Ui {
class ModificarVuelo;
}

class ModificarVuelo : public QDialog
{
    Q_OBJECT

public:
    explicit ModificarVuelo(QWidget *parent = nullptr);
    ~ModificarVuelo();

    void setCiudades(const QString &origen, const QString &destino);

signals:
    void vueloModificado(QString origen, QString destino, double nuevoPeso);

private slots:
    void on_button_Aceptar_clicked();

private:
    Ui::ModificarVuelo *ui;
};

#endif // MODIFICARVUELO_H
