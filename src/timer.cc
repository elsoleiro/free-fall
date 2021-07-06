#include "../include/timer.h"

void timer(int)
{
    glutPostRedisplay(); //opengl invokes display next time it gets the chance

    glutTimerFunc(1, timer, 0); 

}


