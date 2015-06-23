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
    void setZ(float z);
    
    float getX(void);
    float getY(void);
    float getZ(void);

    void moveX(float move);
    void moveY(float move);
    void moveZ(float move);

    void die(void);

protected:
    float x;
    float y;
    float z;
    float xrot;
    float yrot;
    float zrot;
private:

};
