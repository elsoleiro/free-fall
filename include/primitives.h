#ifndef DRAWCIRCLE_H
#define DRAWCIRCLE_H

#include <math.h>
#include "GL/freeglut.h"
#include "GL/glut.h"

class Shape {
    public:
     //   GLfloat pos;
        GLfloat x; 
        GLfloat y;

        Shape (GLfloat x_val, GLfloat y_val):
            x (x_val),
            y (y_val)
    //       pos (pos_val)
    {}
};

class Circle: Shape {
    public:
        GLfloat r;
        GLfloat triangles;

        Circle (GLfloat x, GLfloat y, GLfloat r_val, GLfloat tri_val):
            Shape (x, y),
            r (r_val),
            triangles (tri_val)
    {}
        int getY() {
            return y;
        }

        int getR() {
            return r;
        }

        void draw() {
            int i;
            GLfloat tau = 2.0f * M_PI;

            glBegin(GL_TRIANGLE_FAN);
            {
                glVertex2f(x,y); // origin
                for(i = 0; i <= triangles; i++)
                {
                    glVertex2f(
                            x + (r * cos(i * tau / triangles)),
                            y + (r * sin(i * tau / triangles)));
                }
            }
        }

        void fall(double t) {

            if(y >= r)
            {
                y = y - 4.9*(((t)*(t))/100);
            }
        }
};

#endif
