#include "../include/display.h"
#include "../include/primitives.h"
#include <chrono>
int main(int argc, char** argv) // int is the count of cmd line arguments, char is an array where the args are stored.
{
    void gameLoop();
    glutInit(&argc, argv);
    gameLoop();
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
}

