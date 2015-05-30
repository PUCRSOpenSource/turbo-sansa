#include "Handle.h"

Handle::Handle(void)
{

}
Handle::~Handle(void)
{

}
void Handle::draw(void)
{
        //handleKeys();
}

void Handle::keyboard(unsigned char key, int x, int y)
{
        keys[key] = true;
}

void Handle::specialKeys(int key, int x, int y)
{
        keys[key] = true;
}

void Handle::handleKeys()
{
        //TODO
}
