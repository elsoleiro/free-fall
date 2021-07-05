#include "../include/primitives.h"

void drawCircle(GLfloat x, GLfloat y, GLfloat r)
{
    int i;
    int triangle_count = 200;

    GLfloat tau = 2.0f * M_PI;

    glBegin(GL_TRIANGLE_FAN);
    {
        glVertex2f(x,y);
        for(i = 0; i <= triangle_count; i++)
        {
            glVertex2f(
                    x + (r * cos(i * tau / triangle_count)),
                    y + (r * sin(i * tau / triangle_count)));
        }
    }
}


