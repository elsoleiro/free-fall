#include "../include/display.h"
#include <iostream>

Circle c1(25,50,2,500);

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    c1.draw();
    c1.fall();
    glEnd();
    glutSwapBuffers();
}

void initialise()
{
    glEnable(GL_FRAMEBUFFER_SRGB);
    glClearColor(0.0, 0.0, 0.0, 1.0); // color val used by clear function to clear the color buffer. pretty much, the bg.
}

void resize(int width, int height) 
{
    if (height == 0)
    {
        height = 1;
    }
    if (width == 0)
    {
        width = 1;
    }

    glViewport(0, 0, (GLsizei)width, (GLsizei)height); 
    glMatrixMode(GL_PROJECTION); // modern matrix stores objs, scaling and rotation, this is just projection.
    glLoadIdentity(); 
    gluOrtho2D(0,50,0,50);
    glMatrixMode(GL_MODELVIEW);
}




