class Handle
{
public:
        Handle(void);
        ~Handle(void);
        static void draw(void);
        static void keyboard(unsigned char key, int x, int y);
        static void specialKeys(int key, int x, int y);
        static void handleKeys();
private:
        bool keys[256];
};
