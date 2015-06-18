#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>

using namespace std;
class Vector3
{
        public:
                GLfloat vec[3];

                Vector3(void);
                Vector3(GLfloat x, GLfloat y, GLfloat z);
                Vector3(const GLfloat *v);
                Vector3(const Vector3 &v);
                Vector3& operator= (const Vector3& v);
                void set(GLfloat x, GLfloat y, GLfloat z);

                GLfloat& operator[](int i);
                GLfloat operator[](int i) const;

                Vector3& operator+=(const Vector3& v);
                Vector3& operator-=(const Vector3& v);
                Vector3& operator*=(GLfloat s);
                Vector3& operator/=(GLfloat s);
                Vector3 operator+(const Vector3& v) const;
                Vector3 operator-(const Vector3& v) const;
                Vector3 operator*(GLfloat s) const;
                Vector3 operator/(GLfloat s) const;
                Vector3 operator-(void) const;
                bool operator==(const Vector3& v) const;
                bool operator!=(const Vector3& v) const;

                GLfloat length(void) const;
                GLfloat lengthSquared(void) const;
                void normalize(void);
                GLfloat dot(const Vector3& v) const;
                Vector3 cross(const Vector3& v) const;
                GLfloat distance(const Vector3& v) const;
                GLfloat distanceSquared(const Vector3& v) const;

                void drawLine(void) const;

                static const Vector3 Zero;
                static const Vector3 X_Axis;
                static const Vector3 Y_Axis;
                static const Vector3 Z_Axis;

        private:
};
