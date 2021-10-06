#ifndef ESFERAGRAFICA_H
#define ESFERAGRAFICA_H

//Librerias basicas para graficar
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>

//Libreria personal
#include "esferafisica.h"


class EsferaGrafica: public QGraphicsItem
{
public:
    EsferaGrafica(float x,float y,float r,float m);
    ~EsferaGrafica();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setEscala(float s);
    void actualizar(float dt,float v_lim);
    EsferaFisica* getEsfera();

private:
    EsferaFisica* esfera;
    float escala;
};

#endif // ESFERAGRAFICA_H
