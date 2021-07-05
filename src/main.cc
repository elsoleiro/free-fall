#include "../include/display.h"

int main(int argc, char** argv) // int is the count of cmd line arguments, char is an array where the args are stored.
{
    // callback - make controls.h later if req.
    void keyboard(unsigned char, int, int);

    glutInit(&argc, argv);
    glutInitDisplayMode(GL_DOUBLE | GLUT_RGB); // double for frame forward and back buffers.
    glutInitWindowSize(600,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Free-fall");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(resize);
    initialise();

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

