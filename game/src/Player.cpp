#include "Player.h"
Player::Player():GameObject()
{
        setX(0);
        setY(0);
        setZ(0);
        setXrot(0);
        setYrot(0);
        setZrot(0);
        setCamRadius(20.0f);
}
void Player::draw()
{
        glLoadIdentity();
        glTranslatef(0.0f, 0.0f, -camRadius);
        glRotatef(-xrot,1.0,0.0,0.0);
        glColor3f(1.0f, 0.0f, 0.0f);
        glutSolidCube(2);
        glRotatef(yrot,0.0,1.0,0.0);
        glTranslated(-x,0.0f,-z);
}
void Player::moveCamera(int camX, int camY)
{
        int diffx=(float)(camX-x);
        int diffy=(float)(camY-y);
        x=camX;
        y=camY;
        xrot+=  diffy*0.1;
        yrot+=  diffx;
}
