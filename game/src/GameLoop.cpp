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

void ground(void)
{
	glColor3f(0,0,1);
	glLineWidth(1);
	glBegin(GL_LINES);
	for(float z=-1000; z<=1000; z+=8)
	{
		glVertex3f(-1000,-0.1f,z);
		glVertex3f( 1000,-0.1f,z);
	}
	for(float x=-1000; x<=1000; x+=8)
	{
		glVertex3f(x,-0.1f,-1000);
		glVertex3f(x,-0.1f,1000);
	}
	glEnd();

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
        glViewport(0, 0, w, h);
        //glViewport(w/2, h/2, w, h);
        fAspect = (GLfloat)w/(GLfloat)h;
        init();
}

void keyPressed(unsigned char key, int x, int y)
{

        keys[key] = true;
}
void keyUp(unsigned char key, int x, int y)
{
        keys[key] = false;
}
void handleKeys(void)
{
        if (keys[27])
                exit(0);           
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
        glutKeyboardFunc(keyPressed); 
        glutKeyboardUpFunc(keyUp);
        glutMainLoop();

        return 0;
}
