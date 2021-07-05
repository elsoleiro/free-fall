#include "../include/freeglut.h"
#include "../include/gl.h"
#include <math.h>
#define _USE_MATH_DEFINES

float x_position = -10;
int state = 1;


int main(int argc, char** argv) // int is the count of cmd line arguments, char is an array where the args are stored.
{
    //function declarations
    void resize(int, int);
    void display();
    void keyboard(unsigned char, int, int);
    //void timer(int);
    void initialise();

    glutInit(&argc, argv);
    //single buffer is used when no animation, double buffer is used when there is. 
    glutInitDisplayMode(GL_DOUBLE | GLUT_RGB); 
    glutInitWindowSize(600,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("test");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(resize);
    //glutTimerFunc(0, timer, 0);
    initialise();

    glutMainLoop();

}

void initialise()
{
    glEnable(GL_FRAMEBUFFER_SRGB);
    glClearColor(0.0, 0.0, 0.0, 1.0); // color val used by clear function to clear the color buffer. pretty much, the bg.
}

void resize(int width, int height) // callback is comm between os and window
{
    if (height == 0)
    {
        height = 1;
    }
    if (width == 0)
    {
        width = 1;
    }

    glViewport(0, 0, (GLsizei)width, (GLsizei)height); // passing width and height the changed width and height.
    glMatrixMode(GL_PROJECTION); // modern matrix stores objs, scaling and rotation, this is just projection.
    glLoadIdentity(); // specify values for projection matrix
    //gluPerspective(150, (float)width/(float)height, 0.1, 100.0); // near plane and far plane, this is the angle inbetween, distance from viewer to the near plane and then far distance,
    gluOrtho2D(-10,10,-10,10);
    glMatrixMode(GL_MODELVIEW);
}



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

// FIND THE MINIMUM AMOUNT OF TRIANGLES REQUIRED TO BUILD CIRCLE FOR RADIUS N
// USE THE ANIMATION STUFF TO MAKE IT ANIMATE ONE TRIANGLE AT A TIME

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
	drawCircle(0, 0, 3);

/**
    glBegin(GL_POLYGON);
    glVertex2f(x_position,1.0);
    glVertex2f(x_position,-1.0);
    glVertex2f(x_position+2,-1.0);
    glVertex2f(x_position+2,1.0);
**/

    glEnd();

    glutSwapBuffers();
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

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60, timer, 0);
    
    switch(state)
    {
        case 1:
            if(x_position < -1)
            {
                x_position += 0.15;
            }
    }
}
