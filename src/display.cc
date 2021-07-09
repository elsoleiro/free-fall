#include "../include/timer.h"
#include "../include/display.h"
#include <iostream>
#include <chrono>

Circle c1(250,504,4,500);
// OUTSIDE GAME LOOP -- HOW LONG HAS THE PROGRAM BEEN RUNNING
auto start = std::chrono::steady_clock::now();

void gameLoop() {
    // callback - make controls.h later if req.
        void keyboard(unsigned char, int, int);

        glutInitDisplayMode(GLUT_DOUBLE| GLUT_RGB); // double for frame forward and back buffers.
        glutInitWindowSize(500,500);
        glutInitWindowPosition(0,0);
        glutCreateWindow("Free-fall");


        glutKeyboardFunc(keyboard);
        glutReshapeFunc(resize);
        initialise();

        glutDisplayFunc(display);
        glutTimerFunc(1, timer, 0);

        glutMainLoop();
    };

void display()
{
    // INSIDE LOOP
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




