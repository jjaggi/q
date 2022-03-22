#include<cmath>
#include<GL/glut.h>
struct Point{
GLint x;
GLint y;
};
struct Color{
GLfloat r ;
GLfloat g;
GLfloat b;
}; void
init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glPointSize(1.0f);
}void draw_dda(Point p1, Point p2) {
	GLfloat dx = p2.x - p1.x;
	GLfloat dy = p2.y - p1.y;
	GLfloat x1 = p1.x;
	GLfloat y1 = p1.y;
	GLfloat step = 0; if
		(abs(dx) > abs(dy)) {
		step = abs(dx);
	}
	else {
		step =
			abs(dy);
	}
	GLfloat xInc = dx / step;
	GLfloat yInc = dy / step; for
		(float i = 1; i <= step; i++) {
		glVertex2i(x1,
			y1); x1 += xInc;
		y1 += yInc;
	}
}
Color getPixelColor(GLint x, GLint y) {
	Color color;
	glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &color); return
		color;
}
void setPixelColor(GLint x, GLint y, Color color) {
	glColor3f(color.r, color.g, color.b);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}void boundaryFill4(int x, int y, Color fill_color, Color
	boundary_color) {
	Color currentColor = getPixelColor(x, y); if
		(currentColor.r != boundary_color.r && currentColor.g !=
			boundary_color.g && currentColor.b != boundary_color.b) {
		setPixelColor(x, y, fill_color); boundaryFill4(x +
			1, y, fill_color, boundary_color); boundaryFill4(x,
				y + 1, fill_color, boundary_color);
		boundaryFill4(x - 1, y, fill_color, boundary_color);
		boundaryFill4(x, y - 1, fill_color, boundary_color);
		boundaryFill4(x+1, y - 1, fill_color, boundary_color); boundaryFill4(x-1, y - 1, fill_color, boundary_color);
		boundaryFill4(x-1, y + 1, fill_color, boundary_color);
		boundaryFill4(x+1, y + 1, fill_color, boundary_color);
	}
}
#define VERTEX_COUNT 6
Point points[VERTEX_COUNT] = { 100,100,120,150,100,100,
160,70,130,150,150,150 };
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	Point stPoint =	points[0]; 
	Point b = { 100,200 };
	draw_dda(stPoint, b);
	Point c= { 120,200 };
	//Point b = { 120,150 };
	draw_dda(b, c);
	//Point b = { 120,150 };
	Point d = { 120,100 };
	//Point b = { 120,150 };
	draw_dda(c, d);
	draw_dda(d, stPoint);
	glEnd();
	glFlush();
	Color fillColor = { 1.f,1.0f,0.0f }; Color
		boundaryColor = { 0.0f,0.0f,0.0f };
	boundaryFill4(105,105, fillColor, boundaryColor);
}int main(int argc, char**
	argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("BoundaryFill4-connected");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
