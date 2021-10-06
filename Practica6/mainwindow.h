#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QFile>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "esferafisica.h"
#include "esferagrafica.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void actualizar();

    void on_actionAgregar_Esfera_triggered();

    void on_actionDetener_Simulacion_triggered();

    void on_actionIniciar_Simulacion_triggered();

    void on_actionCerrar_triggered();

private:
    Ui::MainWindow *ui;
    QTimer *tiempo;
    QGraphicsScene *scene;
    float dt;
    int alto;  //v_lim, tamaño en Y de la escena
    int ancho; //h_lim  tamaño en X de la escena
    void ColisionBordes(EsferaFisica *aux);
    QList<EsferaGrafica*> bars;
    float e;



};

#endif // MAINWINDOW_H
