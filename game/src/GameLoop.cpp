
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "GameObject.h"

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <vector>

using namespace std;

std::vector<GameObject*> enemies;
std::vector<GameObject*> bullets;
GameObject* ship;
Map* map;
float bottomY;
float topY;
long timeBefore;
long timeNow;

void draw(void)
{
        timeNow = glutGet(GLUT_ELAPSED_TIME);
        if (timeNow - timeBefore > 20) {
                bottomY += 0.009;
                topY += 0.009;
                ship->moveUp();

                for(unsigned int i = 0; i < bullets.size(); i++) {
                        bullets[i]->moveUp();
                        bullets[i]->moveUp();
                }

                for(unsigned int i = 0; i < enemies.size(); i++) {
                        enemies[i]->zigzag();
                }
                timeBefore = timeNow;
        }

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(-1.0,1.0,bottomY,topY);
        glMatrixMode(GL_MODELVIEW);
        glutReshapeWindow(350, 1050);
        glClearColor(0.0f,0.0f,0.0f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glPushMatrix();
        glLoadIdentity();
        glPopMatrix();
        glLoadIdentity();
        map->drawMap();
        ship->draw();
        for (unsigned int i = 0; i < enemies.size(); i++) {
                enemies[i]->draw();
        }

        for (unsigned int i = 0; i < bullets.size(); i++) {
                bullets[i]->draw();
        }

        for (unsigned int i = 0; i < enemies.size(); i++) {
                if(ship->hasContact(enemies[i])) 
                {
                        std::cout << "You DIED!!!!" << std::endl;
                        exit(0);
                }
                for (unsigned int j = 0; j < bullets.size(); j++) {
                        if (enemies.size() <= 0) {
                                break;
                        }
                        if (bullets[j]->hasContact(enemies[i])) {
                                enemies.erase(enemies.begin() + i);
                                bullets.erase(bullets.begin() + j);
                        }
                }

        }    
        //FIXME
        if(enemies.size()==0){
                std::cout << "YOU WIN!!" << std::endl;
                exit(0);
        }
        glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
        switch (key) {
                case 27:
                        exit(0);
                        break;
                case 'a':
                        if(ship->getX() > -0.9)
                                ship->moveLeft();
                        break;
                case 'd':
                        if(ship->getX() < 0.9)
                                ship->moveRight();
                        break;
                case 'w':
                        GameObject* bullet;
                        bullet = new Bullet(ship->getX(), ship->getY() + 0.12);
                        bullets.push_back(bullet);
                        break;
                default:
                        break;
        }

        glutPostRedisplay();
}

void init(void)
{
        glMatrixMode(GL_PROJECTION);
        bottomY = -1.0;
        topY = 1.0;
        gluOrtho2D(-1.0,1.0,bottomY,topY);
        glMatrixMode(GL_MODELVIEW);
}

int main(int argc, const char *argv[])
{
        int glargc = 0;
        char *glargv[] = { (char *)"gl", 0 };

        //THE ship
        ship = new Ship();
        map = new Map();
        for (int i = 0; i < 10; i++) {
                int random = rand() % 10;
                float frandom = random / 10.0;
                GameObject* enemy;
                enemy = new Enemy(0 + frandom, i + frandom, i % 2);
                enemies.push_back(enemy);
        }

        glutInit(&glargc,glargv);
        timeNow = glutGet(GLUT_ELAPSED_TIME);
        timeBefore = glutGet(GLUT_ELAPSED_TIME);
        timeNow = glutGet(GLUT_ELAPSED_TIME);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(350,1050);
        glutCreateWindow("Lollipop");
        glutDisplayFunc(draw);
        glutKeyboardFunc (keyboard);
        glutIdleFunc(draw);
        init();
        glutMainLoop();
        return 0;
}
