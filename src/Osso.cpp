#include <stdio.h>
#include <stdlib.h>
#include <GL\gl.h>
#include <GL\glut.h>

#include "Osso.h"

/*

Osso::Osso(){
    //ctor
}

Osso::~Osso(){
    //dtor
}
*/

void Osso::desenha(){
    glPushMatrix();  //salva o contexto(1)

      glTranslatef (0.0, altura/2.0, 0.0); //vai para o meio do osso

      glPushMatrix();   //salva o contexto(2)
        glScalef (largura, altura, largura);  //escala para o tamanho do osso

        glutSolidCube (largura);    //desenha o osso
      glPopMatrix();    //restaura o contexto(2)

      glTranslatef (0.0, altura/2.0, 0.0); // vai para a ponta do osso

      glutSolidSphere(0.85*largura,8,8);        //desenha a bolinha

      if (conexcao)
      {
          glRotatef(angulo, 1.0, 0.0, 0.0); //rotaciona para o angulo da conexcao
          conexcao->desenha();              //desenha recursivamente
      }

    glPopMatrix();  //restaura o contexto(1)
};
