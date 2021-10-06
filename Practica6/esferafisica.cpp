#include "esferafisica.h"
#include <math.h>


EsferaFisica::EsferaFisica(float x, float y, float r, float m):px(x),py(y),radio(r),vx(0),vy(0),masa(m)
{

}

EsferaFisica::~EsferaFisica()
{

}

void EsferaFisica::setVelocidad(float x, float y)
{
    vx=x;
    vy=y;
}

void EsferaFisica::setPosicion(float x, float y)
{
    px=x;
    py=y;
    vx=0;
    vy=0;
}

void EsferaFisica::actualizar(float dt)
{
    acelerar(dt);
    vx=vx+ax*dt;
    vy=vy+ay*dt;
    px=px+vx*dt+(ax*pow(dt,2))/2;
    py=py+vy*dt+(ay*pow(dt,2))/2;

}

void EsferaFisica::acelerar(float dt)
{
    ax=0;
    ay=-10;

}

float EsferaFisica::getX() const
{
    return px;
}

float EsferaFisica::getY() const
{
    return py;
}

float EsferaFisica::getR() const
{
    return radio;
}

float EsferaFisica::getVx() const
{
    return vx;
}

float EsferaFisica::getVy() const
{
    return vy;
}
