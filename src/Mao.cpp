#include <stdio.h>
#include <stdlib.h>
#include <GL\gl.h>
#include <GL\glut.h>
#include <windows.h>

#include "Mao.h"



//Construtor
Mao::Mao(float gros): grossura(gros),mindinho(4*grossura,grossura),anelar(6*grossura,grossura),maior(7*grossura,grossura),indicador(6*grossura,grossura),dedao(4*grossura,grossura){
    for (int i=0;i<5;i++)
        curvatura[i] = 0;
}

/*

Mao::~Mao(){//destrutor
}

*/

void display();

void Mao::desenha(){
    glPushMatrix();
      glTranslatef(0.0,6.0*grossura,0.0);
      glPushMatrix();
        glTranslatef(-3*grossura,0.0,0.0);
        glutSolidSphere(grossura,8,8);
        glRotatef(curvatura[0]*0.9,1.0,0.0,0.0);
        mindinho.desenha();
      glPopMatrix();
      glPushMatrix();
        glTranslatef(-1.5*grossura,0.0,0.0);
        glutSolidSphere(grossura,8,8);
        glRotatef(curvatura[1]*0.9,1.0,0.0,0.0);
        anelar.desenha();
      glPopMatrix();
      glPushMatrix();
        glutSolidSphere(grossura,8,8);
        glRotatef(curvatura[2]*0.9,1.0,0.0,0.0);
        maior.desenha();
      glPopMatrix();
      glPushMatrix();
        glTranslatef(1.5*grossura,0.0,0.0);
        glutSolidSphere(grossura,8,8);
        glRotatef(curvatura[3]*0.9,1.0,0.0,0.0);
        indicador.desenha();
      glPopMatrix();
      glPushMatrix();
        glTranslatef(2*grossura,-4*grossura,0.0);
        glRotatef(-80,0.0,0.0,1.0);
        glRotatef(-20,0.0,1.0,0.0);
        glRotatef(curvatura[4]*0.5,1.0,0.0,0.0);
        glScalef(1.5,1,1);
        glutSolidSphere(grossura,8,8);
        dedao.desenha();
      glPopMatrix();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-0.75*grossura,3.0*grossura,0.0);
        glScalef(5.5*grossura,6.0*grossura,1.25*grossura);
        glutSolidCube(1.0);
    glPopMatrix();
}

void Mao::setCurvatura(int dedo,float curv){
    curvatura[dedo] = curv;
    switch(dedo){
        case 0: mindinho.setCurvatura(curv); break;
        case 1: anelar.setCurvatura(curv); break;
        case 2: maior.setCurvatura(curv); break;
        case 3: indicador.setCurvatura(curv); break;
        case 4: dedao.setCurvatura(curv); break;
    }
}

void Mao::abrir(bool tudoJunto){
    if (tudoJunto)
        for (int j=getCurvatura(1);j>=0;j-=5)
        {
            for (int i=4;i>=0;i--)
            {
                setCurvatura(i,j);

            }
            display();
        }
    else
        for (int i=4;i>=0;i--)
        {
            for (int j=getCurvatura(i);j>=0;j-=5)
            {
                setCurvatura(i,j);
                display();
            }
        }

}

void Mao::fechar(bool tudoJunto){
    if (tudoJunto)
    for (int j=getCurvatura(1);j<=100;j+=5)
    {
        for (int i=0;i<5;i++)
        {
            setCurvatura(i,j);
        }
        display();
    }
    else
    for (int i=0;i<5;i++)
    {
        for (int j=getCurvatura(i);j<=100;j+=5)
        {
            setCurvatura(i,j);
            display();
        }
    }
}

void Mao::tchau(){
    abrir(true);
    for(int j = 0 ;j < 3 ; j++){
        ang3 += 5;
        display();
    }
    for(int i = 0; i< 3; i++)
    {
        for(int j = 0 ;j < 6 ; j++)
        {
            ang3 -= 5;
            display();
        }
        for(int j = 0 ;j < 6 ; j++)
        {
            ang3 += 5;
            display();
        }
    }
    for(int j = 0 ;j < 3 ; j++)
    {
        ang3 -= 5;
        display();
    }
}


void Mao::fuck(){
    for(int i = 0 ; i < 180; i+=20)
    {
        ang += 20;
        display();
    }

    fechar(true);
    for (int j=getCurvatura(2);j>=0;j-=20)
    {
        setCurvatura(2,j);
        display();
    }
}

void Mao::hangloose(){
    fechar(true);
    for (int j=getCurvatura(2);j>=0;j-=20)
    {
        setCurvatura(0,j);
        setCurvatura(4,j);
        ang3 += 3;
        display();
    }
    for(int j = 0 ;j < 3 ; j++)
    {
        ang += 5;
        display();
    }
    for(int i = 0; i< 3; i++)
    {
        for(int j = 0 ;j < 6 ; j++)
        {
            ang -= 5;
            display();
        }
        for(int j = 0 ;j < 6 ; j++)
        {
            ang += 5;
            display();
        }
    }
    for(int j = 0 ;j < 3 ; j++)
    {
        ang -= 5;
        display();
    }
    for(int j = 0 ;j < 6 ; j++)
    {
        ang3 -= 3;
        display();
    }
}

void Mao::vemProPau(){
    abrir(true);
    for(int i = 0 ; i < 180; i+=20)
    {
        ang += 20;
        ang2 -=10;
        display();
    }
    for (int j=getCurvatura(1);j<=30;j+=10)
    {
        for (int i=0;i<4;i++)
        {
            setCurvatura(i,j);
        }
        display();
    }
    for (int j=30;j>=0;j-=10)
    {
        for (int i=0;i<4;i++)
        {
            setCurvatura(i,j);
        }
        display();
    }
//////////////
    for (int j=getCurvatura(1);j<=30;j+=10)
    {
        for (int i=0;i<4;i++)
        {
            setCurvatura(i,j);
        }
        display();
    }
    for (int j=30;j>=0;j-=10)
    {
        for (int i=0;i<4;i++)
        {
            setCurvatura(i,j);
        }
        display();
    }


}

void Mao::home(){
    abrir(true);

    if (ang < 0)
        ang += 360;
    if (ang2< 0)
        ang2+= 360;
    if (ang3< 0)
        ang3+= 360;


    while (ang > 0)
    {
        ang-= 10;
        display();
    }
    ang = 0;
    while (ang2 > 0)
    {
        ang2-= 10;
        display();
    }
    ang2 = 0;
    while (ang3 > 0)
    {
        ang3-= 10;
        display();
    }
    ang3 = 0;
    display();

}


void Mao::dedoDuro(){
}

void Mao::positivo(){
}

























