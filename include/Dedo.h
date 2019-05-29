#ifndef DEDO_H
#define DEDO_H

#include "Osso.h"

class Dedo{
    public:
        Dedo(float comprimento, float largura);
        void desenha() {a.desenha();}
        void setCurvatura(float curvatura);
        float getCurvatura() {return a.getAngulo()*100/90;}

    protected:
        Osso a,b,c;
};
#endif // DEDO_H
