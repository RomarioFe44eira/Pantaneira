
#include "Dedao.h"

Dedao::Dedao(float comprimento, float largura):a(comprimento*0.5,largura), b(comprimento*0.5,largura){
    a.setConexcao(&b,0.0);
}

/*

Dedao::~Dedao(){//dtor
}


*/


void Dedao::setCurvatura(float curvatura){
    a.setAngulo(curvatura*0.9);
}
