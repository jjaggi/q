#include <GL/glut.h>
#include <cmath>

int ww = 600, wh = 500;
float fillCol[3] = { 0.4,0.0,0.0 };
float borderCol[3] = { 0.0,0.0,0.0 };
void setPixel(int pointx, int pointy, float f[3])
{
	glBegin(GL_POINTS);
	glColor3fv(f);
	glVertex2i(pointx, pointy);
	glEnd();
	glFlush();
}
void getPixel(int x, int y, float pixels[3])
{
	glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, pixels);
}
void boundaryFill4(int x, int y, float fillColor[3], float borderColor[3])
{
	float interiorColor[3];
	getPixel(x, y, interiorColor);
	if ((interiorColor[0] != borderColor[0] && (interiorColor[1]) != borderColor[1] && (interiorColor[2]) != borderColor[2]) && (interiorColor[0] != fillColor[0] && (interiorColor[1]) != fillColor[1] && (interiorColor[2]) != fillColor[2]))
	{
		setPixel(x, y, fillColor);
		boundaryFill4(x + 1, y, fillColor, borderColor);
		boundaryFill4(x - 1, y, fillColor, borderColor);
		boundaryFill4(x, y + 1, fillColor, borderColor);
		boundaryFill4(x, y - 1, fillColor, borderColor);
	}
}
void drawCircle(GLfloat x, GLfloat y, GLfloat r) {
	glColor3f(0.0, 0.0, 0.0);
	static const double inc = 3.14 / 12;
	static const double max = 2 * 3.14;
	glBegin(GL_LINE_LOOP);
	for (double d = 0; d < max; d += inc) {
		glVertex2f(cos(d) * r + x, sin(d) * r + y);
	}
	glEnd();
	boundaryFill4(x, y, fillCol, borderCol);
}
void display()
{
	glClearColor(0.6, 0.8, 0.1, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	drawCircle(100, 100, 30);
	glFlush();
}

//void mouse(int btn, int state, int x, int y)
//{
//	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
//	{
//		int xi = x;
//		int yi = (wh - y);
//		boundaryFill4(xi, yi, fillCol, borderCol);
//	}
//}
void myinit()
{
	glViewport(0, 0, ww, wh);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)ww, 0.0, (GLdouble)wh);
	glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(ww, wh);
	glutCreateWindow("Bountry-Fill-Recursive");
	glutDisplayFunc(display);
	myinit();
	/*glutMouseFunc(display);*/
	glutMainLoop();
	return 0;
}