#ifndef MAO_H
#define MAO_H


#include "Dedo.h"
#include "Dedao.h"

class Mao{
    protected:
        float grossura;
        Dedo mindinho;
        Dedo anelar;
        Dedo maior;
        Dedo indicador;
        Dedao dedao;
        float curvatura[5];

    public:
        Mao(float grossura);
        void desenha();
        void setCurvatura(int dedo,float curv);
        float getCurvatura(int dedo) {return curvatura[dedo];}
        void abrir(bool tudoJunto = false);
        void fechar(bool tudoJunto = false);
        void tchau();
        void fuck();
        void hangloose();
        void dedoDuro();
        void positivo();
        void vemProPau();
        void home();

        float ang, ang2, ang3;


};

#endif // MAO_H
