#include "GameObject.h"
class Player : public GameObject
{
public:
        Player();
        ~Player();
        void draw();
        void moveCamera(int x, int y);
        void setCamRadius(float radius);
        float getCamRadius();

private:
        float camRadius;
};
