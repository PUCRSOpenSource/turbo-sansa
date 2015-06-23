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
    virtual void moveCamera(int x, int y);

    void setX(float x);
    void setY(float y);
    void setZ(float z);
    
    void setXrot(float xrot);
    void setYrot(float yrot);
    void setZrot(float zrot);

    float getX(void);
    float getY(void);
    float getZ(void);

    float getXrot(void);
    float getYrot(void);
    float getZrot(void);

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
