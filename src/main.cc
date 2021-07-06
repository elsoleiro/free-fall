#include "../include/display.h"
#include "../include/timer.h"
#include <chrono>


int main(int argc, char** argv) // int is the count of cmd line arguments, char is an array where the args are stored.
{
    // callback - make controls.h later if req.
    void keyboard(unsigned char, int, int);

    glutInit(&argc, argv);
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

}

void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 27: glutLeaveMainLoop(); // esc
                 break;
        default: 
                 break;
    }
}

