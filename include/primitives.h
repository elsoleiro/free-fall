#ifndef DRAWCIRCLE_H
#define DRAWCIRCLE_H

#include <math.h>
#include "freeglut.h"
#include "glut.h"

void drawCircle(GLfloat x, GLfloat y, GLfloat r);

class Shape {
    public:
        void setX(GLfloat x_val) {
            x = x_val;
        }

        void setY(GLfloat y_val) {
            y = y_val;
        }
        GLfloat x; 
        GLfloat y;
};

class Circle: public Shape {
    public:
        void setR(GLfloat r_val) {
            r = r_val;
        }

        void setTriangles(GLfloat tri) {
            triangles = tri;
        }

        GLfloat getX() {
            return x;
        }
        GLfloat getR() {
            return r;
        }

        void draw(GLfloat x, GLfloat y, GLfloat r, GLfloat triangles) {
            int i;
            GLfloat tau = 2.0f * M_PI;

            glBegin(GL_TRIANGLE_FAN);
            {
                glVertex2f(x,y);
                for(i = 0; i <= triangles; i++)
                {
                    glVertex2f(
                            x + (r * cos(i * tau / triangles)),
                            y + (r * sin(i * tau / triangles)));
                }
            }
        }
        GLfloat r;
        GLfloat triangles;
};

#endif
