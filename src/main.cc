#include "../include/display.h"
#include "../include/primitives.h"
#include <chrono>

int main(int argc, char** argv) // int is the count of cmd line arguments, char is an array where the args are stored.
{
    void keyboard(unsigned char, int, int);
    void timer(int);
//    void gameLoop();

    glutInitDisplayMode(GLUT_DOUBLE| GLUT_RGB); // double for frame forward and back buffers.
    glutInit(&argc, argv);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Free-fall");

    glutKeyboardFunc(keyboard);
    glutReshapeFunc(resize);
    initialise();

    glutDisplayFunc(display);
    glutTimerFunc(1, timer, 0); // fence - don't draw next frame whilst still drawing the current frame, PostRedisplay takes care of this

    glutMainLoop();
};


void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 27: glutLeaveMainLoop(); // esc
                 break;
        default: 
                 break;
    }
};

