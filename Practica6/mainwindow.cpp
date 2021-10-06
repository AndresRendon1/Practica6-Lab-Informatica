#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->centralWidget);


    ancho=1000;
    alto=500;
    dt=0.01;

    tiempo=new QTimer(this);
    scene=new QGraphicsScene(this);
    scene->setSceneRect(0,0,ancho,alto);

    ui->graphicsView->setScene(scene);
        qDebug()<<ui->graphicsView->size();
    ui->centralWidget->adjustSize();
        qDebug()<<ui->centralWidget->size();

    qDebug()<<this->size();
    scene->addRect(scene->sceneRect());
    tiempo->stop();
    connect(tiempo,SIGNAL(timeout()),this,SLOT(actualizar()));

    for(int i=0; i<bars.size(); i++){
        bars.at(i)->actualizar(dt,alto);
    }
    tiempo->start(1000*dt);
}


void MainWindow::actualizar()
{
    for(int i=0; i<bars.size(); i++){
        ColisionBordes(bars.at(i)->getEsfera());
        bars.at(i)->actualizar(dt,alto);
    }
}

void MainWindow::ColisionBordes(EsferaFisica *aux)
{
    if(aux->getX()<aux->getR() || aux->getX()>ancho-aux->getR()){
        aux->setVelocidad(-e*aux->getVx(),aux->getVy());
    }
    if(aux->getY()<aux->getR() || aux->getY()>alto-aux->getR()){
      aux->setVelocidad(aux->getVx(),-e*aux->getVy());
    }
}


void MainWindow::on_actionAgregar_Esfera_triggered()
{
    srand(time(NULL));
    float px=0,py=0,radio=0,vx=0,vy=0,masa=0;
    px=rand()% 950+50;
    py=rand()% 450+50;
    radio=rand()% 30+5;
    vx=rand()% 300+1;
    vy=rand()% 300+1;
    masa=rand()% 600+50;
    e=rand()% 1+0.5;      //coheficiente de restitucion

    bars.append(new EsferaGrafica(px,py,radio,masa));
    bars.last()->getEsfera()->setVelocidad(vx,vy);
    scene->addItem(bars.last());
}

MainWindow::~MainWindow()
{
    delete scene;
    delete tiempo;
    delete ui;
}


void MainWindow::on_actionDetener_Simulacion_triggered()
{
    tiempo->stop();
}

void MainWindow::on_actionIniciar_Simulacion_triggered()
{
    tiempo->start();
}

void MainWindow::on_actionCerrar_triggered()
{
    close();
}
