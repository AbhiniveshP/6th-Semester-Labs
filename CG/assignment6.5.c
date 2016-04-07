#include <GL/glut.h>

void Draw() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.25, 0.75, 0.45);
	glBegin(GL_TRIANGLES);
		glVertex2f(0.25, 0.25);
		glVertex2f(0.75, 0.75);
		glVertex2f(0.6, 0.4);

		glVertex2f(0.20, 0.55);
		glVertex2f(0.15, 0.65);
		glVertex2f(0.20, 0.9);
	glEnd();
	glFlush();
}

void Init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

int main(int iArgc, char** cppArgv) {
	glutInit(&iArgc, cppArgv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("GL-TRIANGLES");
	
	glutDisplayFunc(Draw);
	glutMainLoop();
	return 0;
}