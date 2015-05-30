#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include "Handle.h"

int main(void)
{
        int argc = 0;
        char *argv[] = { (char *)"gl", 0 };
        Handle* handle = Handle::Instance();;
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
        glutInitWindowPosition(5,5);
        glutInitWindowSize(450,450);
        glutCreateWindow("Movimentação 3D");
        //glutTimerFunc(33, TimerFunction, 1 ); // 33 ms
        glutDisplayFunc(handle->draw);
        //glutReshapeFunc(reshape);
        glutKeyboardFunc (handle->keyboard);
        glutSpecialFunc(handle->specialKeys);
        //glutMotionFunc(GerenciaMovim);
        //glutMouseFunc(GerenciaMouse);
        glutMainLoop();

        return 0;
}
