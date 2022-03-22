#include<GL/glut.h>
void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 499.0, 0.0, 499.0);
}
void drawLines() {
	glColor3f(0.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(2.0);
	glBegin(GL_TRIANGLES);
	glVertex2d(100.0, 100.0);
	glVertex2d(400.0, 100.0);
	glVertex2d(250.0, 259.8);
	glEnd();
	glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(500, 500);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Equilateral Triangle on Green BG|");
		init();
	glutDisplayFunc(drawLines);
	glutMainLoop();
}