#include "../include/display.h"
#include <math.h>
#define _USE_MATH_DEFINES

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
	drawCircle(0, 0, 3);
    glEnd();
    glutSwapBuffers();
}


