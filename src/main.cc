#include "../include/display.h"

int main(int argc, char** argv) // int is the count of cmd line arguments, char is an array where the args are stored.
{
    // callbacks
    void resize(int, int);
    void keyboard(unsigned char, int, int);
    void initialise();

    glutInit(&argc, argv);
    glutInitDisplayMode(GL_DOUBLE | GLUT_RGB); // double for frame forward and back buffers.
    glutInitWindowSize(600,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("test");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(resize);
    initialise();

    glutMainLoop();

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
    gluOrtho2D(-10,10,-10,10);
    glMatrixMode(GL_MODELVIEW);
}

/**

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


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
	drawCircle(0, 0, 3);
    glEnd();
    glutSwapBuffers();
}
**/

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

