#include "../include/display.h"

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    drawCircle(0, 0, 3);
    glEnd();
    glutSwapBuffers();
}


