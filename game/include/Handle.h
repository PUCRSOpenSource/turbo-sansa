class Handle
{
public:
        ~Handle(void);
        static void draw(void);
        static void keyboard(unsigned char key, int x, int y);
        static void specialKeys(int key, int x, int y);
        static void handleKeys();
        static Handle* Instance();
private:
        Handle(void);
        Handle(const Handle &);
        Handle& operator=(const Handle &);

        bool keys[256];
};
