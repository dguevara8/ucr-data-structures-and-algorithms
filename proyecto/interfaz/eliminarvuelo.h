#ifndef ELIMINARVUELO_H
#define ELIMINARVUELO_H

#include <QDialog>
#include "../graphs.h"

namespace Ui {
class EliminarVuelo;
}

class EliminarVuelo : public QDialog
{
    Q_OBJECT

public:
    explicit EliminarVuelo(QWidget *parent, Graph &graphRef);
    ~EliminarVuelo();

    void cargarVuelos(const QVector<QPair<QString, QString>> &listaVuelos);

signals:
    void vueloEliminado(QString origen, QString destino);

private slots:
    void on_button_Eliminar_clicked();

private:
    Ui::EliminarVuelo *ui;
    Graph &graph;

};

#endif // ELIMINARVUELO_H
