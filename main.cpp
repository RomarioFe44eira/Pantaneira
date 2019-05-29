#include <stdio.h>
#include <stdlib.h>
#include <GL\gl.h>
#include <GL\glut.h>
//#include <gl\glaux.h>
//#include "utilTextura.cpp"

//#include "include/Osso.h"
#include "include/Mao.h"



void display();
/////////   VARI�VEIS GLOBAIS PARA OS ANGULOS////////////



void display();

/////////////////////////////////////////////////////////////
Mao m(1.0);

///////////////////////////////////////////////////
void init(void){
//  LoadGLTextures();
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glClearDepth(1.0);				// Enables Clearing Of The Depth Buffer
    glDepthFunc(GL_LEQUAL);				// The Type Of Depth Test To Do
    glEnable(GL_DEPTH_TEST);			// Enables Depth Testing
    glShadeModel(GL_SMOOTH);			// Enables Smooth Color Shading
}

void display(void){
   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//   glBindTexture(GL_TEXTURE_2D, texture[0]);
   //////////////ISSO AQUI EH PRA LUZ///////////E EU AINDA N SEI COMO FUNCA/////
    GLfloat			diffuseLight[] = { 1.0f, 1.0f, 1.0f, 1.0};
    GLfloat			ambientLight[] = { 0.2f, 0.2f, 0.4f, 1.0};
    GLfloat			lightPos[] = { 0.0f, 500.0f, 100.0f, 1.0f };
    glEnable(GL_LIGHTING);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT0, GL_SPECULAR, diffuseLight);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glColor3f(1.0f,1.0f,1.0f);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, diffuseLight );
    glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, 50);
    //////////////////////////////////////////////////////////////////////////

    glPushMatrix();
      glTranslatef (0.0, -5.0, -15.0);
      glRotatef (ang3, 0.0, 0.0, 1.0);
      glRotatef (ang, 0.0, 1.0, 0.0);
      glRotatef (ang2, 1.0, 0.0, 0.0);
      glColor3f(1.0,0.8,0);
      m.desenha();
    glPopMatrix();

    glutSwapBuffers();
}

void reshape (int w, int h){
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(55.0, (GLfloat) w/(GLfloat) h, 1.0, 40.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef (0.0, 0.0, -10.0);
}

void idle(){
}

void keyboard (unsigned char key, int x, int y){
    switch(key){
        case 'q':
            if (m.getCurvatura(0) < 100)
                m.setCurvatura(0,m.getCurvatura(0)+5);
            break;
        case 'a':
            if (m.getCurvatura(0) > 0)
                m.setCurvatura(0,m.getCurvatura(0)-5);
            break;
        case 'w':
            if (m.getCurvatura(1) < 100)
                m.setCurvatura(1,m.getCurvatura(1)+5);
            break;
        case 's':
            if (m.getCurvatura(1) > 0)
                m.setCurvatura(1,m.getCurvatura(1)-5);
            break;
         case 'e':
            if (m.getCurvatura(2) < 100)
                m.setCurvatura(2,m.getCurvatura(2)+5);
            break;
        case 'd':
            if (m.getCurvatura(2) > 0)
                m.setCurvatura(2,m.getCurvatura(2)-5);
            break;
        case 'r':
            if (m.getCurvatura(3) < 100)
                m.setCurvatura(3,m.getCurvatura(3)+5);
            break;
        case 'f':
            if (m.getCurvatura(3) > 0)
                m.setCurvatura(3,m.getCurvatura(3)-5);
            break;
        case 't':
            if (m.getCurvatura(4) < 100)
                m.setCurvatura(4,m.getCurvatura(4)+5);
            break;
        case 'g':
            if (m.getCurvatura(4) > 0)
                m.setCurvatura(4,m.getCurvatura(4)-5);
            break;
        case '.': //>
            ang += 5;
            if (ang>360)
                ang -= 360;
            break;
        case ',': //<
            ang -= 5;
            if (ang<0)
                ang += 360;
            break;
        case ']':
            ang2 += 5;
            if (ang2>360)
                ang2 -= 360;
            break;
        case '[':
            ang2 -= 5;
            if (ang2<0)
                ang2 += 360;
            break;
        case '+':
            m.abrir();
            break;
        case '*' :
            m.abrir(true);
            break;
        case '/' :
            m.fechar(true);
            break;
        case '-':
            m.fechar();
            break;
        case 27: //ESC
            exit(0);
            break;
        case '9':
            ang3 += 5;
            if (ang3>360)
                ang3 -= 360;
            break;
        case '0':
            ang3 -= 5;
            if (ang3<0)
                ang3 += 360;
            break;
        case '1' :
            m.tchau();
            break;
        case '2' :
            m.fuck();
            break;
        case '3' :
            m.hangloose();
            break;
        case '4' :
            m.vemProPau();
            break;
        case 8 :
            m.home();
            break;

        default:
            return;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv){

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize (300, 300);
    glutInitWindowPosition (200, 200);
    glutCreateWindow (argv[0]);
    init ();

    printf("FullScreen?(y/n) ");
    if (getchar() == 'y')
        glutFullScreen();

    glutIdleFunc(idle);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
