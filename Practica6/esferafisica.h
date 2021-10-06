#ifndef ESFERAFISICA_H
#define ESFERAFISICA_H


class EsferaFisica
{
public:
    EsferaFisica(float x,float y, float r,float m);
    ~EsferaFisica();
    void actualizar(float dt);
    void acelerar(float dt);
    void setPosicion(float x,float y);
    void setVelocidad(float x, float y);
    float getX() const;
    float getY() const;
    float getR() const;
    float getVx() const;
    float getVy() const;

private:
    float px;
    float py;
    const float radio;
    float vx;
    float vy;
    float masa;
    float ax;
    float ay;
    float e;

};

#endif // ESFERAFISICA_H
