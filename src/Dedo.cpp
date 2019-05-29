#include "Dedo.h"

Dedo::Dedo(float comprimento, float largura): a(comprimento*0.4,largura), b(comprimento*0.35,largura), c(comprimento*0.25,largura){
    a.setConexcao(&b,0.0);
    b.setConexcao(&c,0.0);
}

/*
Dedo::~Dedo(){
    //dtor
}
*/


void Dedo::setCurvatura(float curvatura){
    a.setAngulo(curvatura*0.9);
    b.setAngulo(curvatura*0.9);
}
