//Code: Circle Using Bresenham Algorithm

#include <GL/glut.h>
#include<stdio.h>
#include<math.h>
int xa, ya, xb, yb;

//user defined function for drawing circle
void circle() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 0.0);
    float r = 100;
    float x = 0, y = r;
    float p = 3 - 2 * r;
    while (x <= y) {
        
        if (p < 0) {
            p += 4*x+6;
            x++;
        }
        else {
            
            p += 4 * (x-y) + 10;
            y--;
            x++;
        }
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glVertex2i(-x, y);
        glVertex2i(x, -y);
        glVertex2i(-x, -y);

        glVertex2i(y, x);
        glVertex2i(-y, x);
        glVertex2i(y, -x);
        glVertex2i(-y, -x);
        glEnd();
    }
    glFlush();
}
//function used for intialisation 
void myinit(void)
{
    glClearColor(0.0, 0.0,0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glPointSize(2);
    glLoadIdentity();
    gluOrtho2D(-250, 500.0, -250, 500.0);
}
//main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Bresenham Circle");
    glutDisplayFunc(circle);
    myinit();
    glutMainLoop();
    return 0;
}