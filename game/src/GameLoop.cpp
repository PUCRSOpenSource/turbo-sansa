#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include "Utils.h"

int main(void)
{
        int argc = 0;
        char *argv[] = { (char *)"gl", 0 };
        Utils* handler = new Utils();
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
        glutInitWindowPosition(5,5);
        glutInitWindowSize(450,450);
        glutCreateWindow("Movimentação 3D");
        //glutTimerFunc(33, TimerFunction, 1 ); // 33 ms
        glutDisplayFunc(handler->draw);
        //glutReshapeFunc(reshape);
        glutKeyboardFunc (handler->keyboard);
        glutSpecialFunc(handler->specialKeys);
        //glutMotionFunc(GerenciaMovim);
        //glutMouseFunc(GerenciaMouse);
        glutMainLoop();

        return 0;
}
