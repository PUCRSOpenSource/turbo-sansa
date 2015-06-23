#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cmath>
#include <stdlib.h>
#include <iostream>

using namespace std;

float xpos = 0, ypos = 0, zpos = 0, xrot = 0, yrot = 0, angle=0.0;
float cRadius = 20.0f; // our radius distance from our character
float lastx, lasty;
bool keys[256];

//positions of the cubes
float positionz[10];
float positionx[10];

//existing cubes
bool exist[10];

void    cube(void);
void    cubepositions(void);
void    display(void);
void    enable(void);
void    init(void);
void    keyPress(unsigned char key, int x, int y);
void    keyUp(unsigned char key, int x, int y);
void    keyboard(void);
int     main(int argc, char **argv);
void    mouseMovement(int x, int y);
void    reshape(int w, int h);
void    testColisions();

void cubepositions (void) { //set the positions of the cubes

        for (int i=0; i<10; i++)
        {
                positionz[i] = rand()%5 + 1;
                positionx[i] = rand()%5 + 1;
        }
}

//draw the cube
void cube (void) {
        for (int i=0; i<10 - 1; i++)
        {
                if (exist[i]) {
                        glPushMatrix();
                        glTranslated(-positionx[i + 1] * 10, 0, -positionz[i + 1] * 10);
                        glutSolidCube(2);
                        glPopMatrix();

                }
                
        }
}

void testColisions (void) {
        for (int i = 0; i < 10; i++) {
                float enemyX = -positionx[i + 1] * 10;
                float enemyZ = -positionz[i + 1] * 10;
                if ((xpos < enemyX + 1 && xpos > enemyX - 1) && (zpos < enemyZ + 1 && zpos > enemyZ - 1) ) {
                        exist[i] = false;
                }
                
        }
        
}

void init (void) {
        cubepositions();
        for (int i = 0; i < 10; i++) {
                exist[i] = true;
        }
}

void enable (void) {
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glEnable(GL_COLOR_MATERIAL);
        glShadeModel(GL_SMOOTH);
}

void display(void)
{
        keyboard();
        glClearColor (0.0,0.0,0.0,1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        enable();
        glLoadIdentity();
        glTranslatef(0.0f, 0.0f, -cRadius);
        glRotatef(xrot,1.0,0.0,0.0);
        glColor3f(1.0f, 0.0f, 0.0f);
        glutSolidCube(2);
        glRotatef(yrot,0.0,1.0,0.0);
        glTranslated(-xpos,0.0f,-zpos);
        glColor3f(1.0f, 1.0f, 1.0f);
        cube();
        testColisions();
        glutSwapBuffers();
}

void reshape(int w, int h)
{
        glViewport(0, 0, (GLsizei)w, (GLsizei)h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(60, (GLfloat)w/(GLfloat)h, 0.1, 100.0);
        glMatrixMode(GL_MODELVIEW);
}
void keyPress(unsigned char key, int x, int y)
{
        keys[key] = true;
}
void keyUp(unsigned char key, int x, int y)
{
        keys[key] = false;
}
void keyboard(void)
{
        float xrotrad, yrotrad;
        yrotrad = (yrot/180 * 3.141592654f);
        xrotrad = (xrot/180 * 3.141592654f);

        if (keys['w'])
        {
                xpos   += float(sin(yrotrad));
                zpos   -= float(cos(yrotrad));
                ypos   -= float(sin(xrotrad));
        }

        if (keys['s'])
        {
                xpos   -= float(sin(yrotrad));
                zpos   += float(cos(yrotrad));
                ypos   += float(sin(xrotrad));
        }

        if (keys['d'])
        {
                xpos   += float(cos(yrotrad)) * 0.5;
                zpos   += float(sin(yrotrad)) * 0.5;
        }

        if (keys['a'])
        {
                xpos   -= float(cos(yrotrad)) * 0.5;
                zpos   -= float(sin(yrotrad)) * 0.5;
        }

        if (keys[27])
        {
                glutLeaveGameMode();
                exit(0);
        }
}

void mouseMovement(int x, int y)
{
        int diffx=x-lastx;
        int diffy=y-lasty;
        lastx=x;
        lasty=y;
        xrot+= (float) diffy;
        yrot+= (float) diffx;
}

int main (int argc, char **argv)
{
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
        glutEnterGameMode();
        init();
        glutDisplayFunc(display);
        glutIdleFunc(display);
        glutReshapeFunc(reshape);
        glutPassiveMotionFunc(mouseMovement);
        glutKeyboardFunc(keyPress);
        glutKeyboardUpFunc(keyUp);
        glutMainLoop();
        return 0;
}
