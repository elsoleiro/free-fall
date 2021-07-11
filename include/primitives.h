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

class Line: Shape {
    public:
        Line (GLfloat x, GLfloat y):
            Shape(x,y)
    {}
};

class Circle: Shape {
    public:
        GLfloat r;
        GLfloat xy;
        GLfloat triangles;

        Circle (GLfloat x, GLfloat y, GLfloat xy_val, GLfloat r_val, GLfloat tri_val):
            Shape (x, y),
            r (r_val),
            xy (xy_val),
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

        void fall(double t, GLfloat dt) { // need to know x,y,dt
            // riemann sum, euler integration
            // we know the actual time, t, and the time between frames dt
            GLfloat v = 9.8*t;
            static GLfloat old_y = y; // single instance exists until EOF

            if(y >= r) 
            {
                // instead of calcing the pos given some time, calc the velocity given some time. use that to update the position. we want to find delta y.
                y -= v*dt;
                // current height = last height + change in height
                // this is an approximation of the derivative.
            }
        }
};

#endif
