#include "../include/display.h"
#include <iostream>
#include <chrono>


auto start = std::chrono::steady_clock::now();
Circle c1(250,505,4,500);
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    c1.draw();
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> time = end-start;

    c1.fall(time.count());
    if ((int)c1.getY() <= c1.getR())
    {
        auto endProg = std::chrono::steady_clock::now();
        std::chrono::duration<double> endtime = endProg-start;
        std::cout << endtime.count() << std::endl;
    }
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
    gluOrtho2D(0,500,0,500);
    glMatrixMode(GL_MODELVIEW);
}




