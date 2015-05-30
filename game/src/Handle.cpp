#include "Handle.h"

Handle::Handle(void)
{

}
Handle::~Handle(void)
{

}
Handle* Handle::Instance()
{
        static Handle instance;
        return &instance;
}
void Handle::draw(void)
{
        //handleKeys();
}

void Handle::keyboard(unsigned char key, int x, int y)
{
        Instance()->keys[key] = true;
}

void Handle::specialKeys(int key, int x, int y)
{
        Instance()->keys[key] = true;
}

void Handle::handleKeys()
{
        //TODO
}
