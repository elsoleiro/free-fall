#include "../include/timer.h"
#include "../include/display.h"
#include <iostream>
#include <chrono>

Circle c1(250,504,504,4,20);
// OUTSIDE GAME LOOP -- HOW LONG HAS THE PROGRAM BEEN RUNNING
auto start = std::chrono::steady_clock::now();
std::chrono::duration<double> dt_time;
auto dt_start = std::chrono::steady_clock::now();

void gameLoop() {
    auto end = std::chrono::steady_clock::now();
    dt_time = end-dt_start;
    dt_start = std::chrono::steady_clock::now();
    std::cout << "Frame time: "<< dt_time.count() << std::endl;
    std::cout << c1.getY() << std::endl;

    };

void display()
{
    gameLoop();
    // INSIDE LOOP
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    c1.draw();
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> time = end-start;


    if ((int)c1.getY() <= c1.getR())
    {
        auto endProg = std::chrono::steady_clock::now();
        std::chrono::duration<double> endtime = endProg-start;
        std::cout << endtime.count() << std::endl;
    }

    glEnd();
    c1.fall(time.count(), dt_time.count());
    glutSwapBuffers();
} 

void initialise() {
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




