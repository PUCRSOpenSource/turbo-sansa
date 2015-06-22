#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "GameObject.h"

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

#define SENS_ROT	5.0
#define SENS_OBS	10.0
#define SENS_TRANSL	30.0
using namespace std;

GLfloat rotX, rotY, rotX_ini, rotY_ini;
GLfloat obsX, obsY, obsZ =200, obsX_ini, obsY_ini, obsZ_ini;
GLfloat fAspect = 1, angle = 44;
int x_ini,y_ini,bot;

float X = -30;
float delta = 0.4;
bool keys[256];


void draw(void);
void drawPlane();
void ground(void);
void handleKeys(void);
void init(void);
void observer(void);

void keyUp(unsigned char key, int x, int y);
void keyboard(unsigned char key, int x, int y);
void resize(GLsizei w, GLsizei h);
void specKeyUp(int key, int x, int y);
void specialKeys(int key, int x, int y);

void observer(void)
{

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(-obsX,-obsY,-obsZ);
        glRotatef(rotX,1,0,0);
        glRotatef(rotY,0,1,0);
        gluLookAt(0.0,40.0,200.0, 0.0,0.0,0.0, 0.0,1.0,0.0);
}
void drawPlane()//Desenha o plano
{
        glBegin(GL_POLYGON);
        glVertex3f(30,0,30);
        glVertex3f(30,0,0);
        glVertex3f(0,0,0);
        glVertex3f(0,0,30);
        glEnd();
}


void ground(void)
{
        glPushMatrix();
        glColor3f(0,1,0);
        glTranslatef(-100,0,-100);
        glScalef(200,200,200);
        drawPlane();
        glPopMatrix();

        glutSwapBuffers();
}

void init(void)
{
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(angle,fAspect,0.5,500);
        observer();
}

void draw(void)
{
        handleKeys();
        init();
        ground();
}

void resize(GLsizei w, GLsizei h)
{
        if ( h == 0 )
                h = 1;
        glViewport(0, 0, w/2, h/2);
        //glViewport(w/2, h/2, w, h);
        fAspect = (GLfloat)w/(GLfloat)h;
        init();
}

//Keys interaction
void keyboard(unsigned char key, int x, int y)
{
        if(key == 27)
                exit(0);

        keys[key] = true;
}
void specialKeys(int key, int x, int y)
{
        keys[key] = true;
}
void keyUp(unsigned char key, int x, int y)
{
        keys[key] = false;
}
void specKeyUp(int key, int x, int y)
{
        keys[key] = false;
}
void handleKeys(void)
{
}

int main(void)
{
        int argc = 0;
        char *argv[] = { (char *)"gl", 0 };
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
        glutInitWindowPosition(5,5);
        glutInitWindowSize(800,800);
        glutCreateWindow("Turbo Sansa");
        //glutTimerFunc(33, TimerFunction, 1 ); // 33 ms
        glutDisplayFunc(draw);
        glutReshapeFunc(resize);
        glutKeyboardFunc (keyboard);
        glutSpecialFunc(specialKeys);
        glutKeyboardUpFunc(keyUp);
        glutSpecialUpFunc(specKeyUp);
        glutMainLoop();

        return 0;
}
