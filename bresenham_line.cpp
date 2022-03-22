#include<GL/glut.h>
#include<iostream>
#include<cmath>
using namespace
std;
float x1, x2, Y1, y2;
void display(void)
{
	int x, y;
	x = x1;
	y = Y1;
	int dx, dy, pk, k, y_inc;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 0);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	dx = x2 - x1; dy
		= y2 - Y1; pk =
		2 * dy - dx; if
		(dx >= 0)y_inc
		= 1; else y_inc
		= -1;
	for (k = 0; k < abs(dx); k++)
	{
		if (pk < 0) {
			pk = pk + 2 * dy;
		}
		else {
			pk = pk + 2 * dy - 2 * dx;
			y = y + y_inc;
		}x++;
		glBegin(GL_POINTS);
		glVertex2i(x, y);
		glEnd();
	}
	glFlush();
}
void init(void)
{
	glClearColor(0, 0, 0, 1);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 400, 0, 400);
}
int main(int argc, char** argv)
{
	cout << "Enterthevalueofx1:";
	cin>>x1;
		cout << "Enterthevalueofy1:";
	cin >> Y1;
	cout << "Enterthevalueofx2:";
	cin >> x2;
	cout << "Enterthevalueofy2:";
	cin >> y2;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Bresenham’s line drawing algorithm");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

