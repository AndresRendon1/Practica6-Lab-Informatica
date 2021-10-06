#include "esferagrafica.h"
#include "QtDebug"

EsferaGrafica::EsferaGrafica(float x, float y, float r, float m):escala(1)
{
    esfera=new EsferaFisica(x,y,r,m);
}

EsferaGrafica::~EsferaGrafica()
{
    delete esfera;
}

QRectF EsferaGrafica::boundingRect() const
{
    return QRectF(-1*escala*esfera->getR(),-1*escala*esfera->getR(),2*escala*esfera->getR(),2*escala*esfera->getR());
}

void EsferaGrafica::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::lightGray);
    painter->drawEllipse(boundingRect());
}

void EsferaGrafica::setEscala(float s)
{
    escala=s;
}

void EsferaGrafica::actualizar(float dt,float alto)
{
    esfera->actualizar(dt);
    setPos(esfera->getX()*escala,(alto-esfera->getY())*escala);

}

EsferaFisica *EsferaGrafica::getEsfera()
{
    return esfera;
}
