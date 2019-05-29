#ifndef DEDAO_H
#define DEDAO_H

#include "Osso.h"

class Dedao{
    public:
        Dedao(float comprimento, float largura);
        void desenha() {a.desenha();}
        void setCurvatura(float curvatura);
        float getCurvatura() {return a.getAngulo()*100/90;}

    protected:
        Osso a,b;
};

#endif // DEDAO_H
