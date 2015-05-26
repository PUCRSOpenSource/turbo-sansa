#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#pragma once

class GameObject
{
public:
    GameObject(void);
    ~GameObject(void);

    virtual void draw(void){};

    void setX(float x);
    void setY(float y);
    
    float getX(void);
    float getY(void);

    void moveX(float move);
    void moveY(float move);

    void moveLeft();
    void moveRight();

    void moveUp();

    void die(void);

    void zigzag();

    void setXmax(float posXmax);

    void setXmin(float posXmin);

    void setYmax(float posYmax);

    void setYmin(float posYmin);

    float getXmax();

    float getYmax();

    float getXmin();

    float getYmin();

    bool hasContact(GameObject *object);

protected:
    float x;
    float y;

    bool zig;

private:
    float xMax;
    float yMax;
    float xMin;
    float yMin;

};
