#include <iostream>
#include <GL/glut.h>
#define _USE_MATH_DEFINES
#include <math.h>

double mer;
double ven;
double bum;
double mar;
double bul;
double pho;
double dei;

void garis(double jari, int vertex, double x1, double x2, double y1, double y2, std::string type) {
	if (type == "orbit") {
		glColor3ub(105, 105, 105);
		glBegin(GL_LINE_LOOP);
		for (int i = 0; i < vertex; i++) {
			double x = jari * cos((2 * M_PI * i) / vertex);
			double y = jari * sin((2 * M_PI * i) / vertex);
			glVertex2d(x1 + x, y1 + y);
		}
		glEnd();

	}
	if (type == "garis") {
		
	}
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	garis(30, 60, 0, 0, 0, 0, "orbit");
	garis(60, 60, 0, 0, 0, 0, "orbit");
	garis(110, 60, 0, 0, 0, 0, "orbit");
	garis(160, 60, 0, 0, 0, 0, "orbit");

	garis(12, 60, sin(bum) * 110, 0, cos(bum) * 110, 0, "orbit");
	garis(12, 60, sin(mar) * 160, 0, cos(mar) * 160, 0, "orbit");
	garis(20, 60, sin(mar) * 160, 0, cos(mar) * 160, 0, "orbit");


	

	
	glutSwapBuffers();
}

void myinit() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-200.0, 200.0, -200.0, 200.0);
}
void infinitiLoop(int) {
	glutTimerFunc(1000 / 100, infinitiLoop, 0);
	glutPostRedisplay();
	
	mer += 1.0 / 88.0 * 2;
	ven += 1.0 / 243.0 * 2;
	bum += 1.0 / 365.0 * 2;
	mar += 1.0 / 687.0 * 2;
	bul += 1.0 / 29.5 * 2;
	pho += 1.0 / 20.0 * 2;
	dei += 1.0 / 25.0 * 2;

}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(650, 650);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Points");
	glutDisplayFunc(display);
	glEnable(GL_POINT_SMOOTH);

	glutTimerFunc(0, infinitiLoop, 0);
	myinit();
	glutMainLoop();

	return 0;
}