#include<cmath>
#include<GL/glut.h>

#include<iostream>
#include<math.h>
#include<GL/glut.h>
#include<iostream>
#include<math.h>
void init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 600.0, 0.0, 600.0);
}

void Display() {
	int anglevalue = 60;
	float cosvalue = cos((anglevalue * 3.14) / 180);
	float sinvalue = sin((anglevalue * 3.14) / 180);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	int x = 300;
	int y = 300;
	glBegin(GL_TRIANGLES);
	glVertex2i(50, 60);
	glVertex2i(100, 50);
	glVertex2i(100, 120);
	glEnd();
	float x1 = 50 * cosvalue - 60 * sinvalue+100;
	float y1 = 60 * cosvalue + 50 * sinvalue + 100;//for visibility
	float x2 = 100 * cosvalue - 50 * sinvalue + 100;
	float y2 = 50 * cosvalue + 100 * sinvalue + 100;
	float x3 = 100 * cosvalue - 120 * sinvalue + 100;
	float y3 = 120 * cosvalue + 100 * sinvalue + 100;
	
	glBegin(GL_TRIANGLES);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glVertex2i(x3, y3);
	glEnd();
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(80, 100);
	glutInitWindowSize(600, 600);
	glutCreateWindow("solution");
	init();
	glutDisplayFunc(Display);
	glutMainLoop();
}
