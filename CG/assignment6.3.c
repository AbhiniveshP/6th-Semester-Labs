#include <GL/glut.h>

void Draw() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINE_STRIP);
		glVertex2f(0.25, 0.25);
		glVertex2f(0.75, 0.75);
		glVertex2f(0.6, 0.4);
		glVertex2f(0.75, 0.45);
		glVertex2f(0.8, 0.25);
		//glVertex2f(0.8, 075);
		glVertex2f(0.4, 0.6);
		glVertex2f(0.8, 0.9);
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
	glutCreateWindow("GL-LINE-STRIP");
	
	glutDisplayFunc(Draw);
	glutMainLoop();
	return 0;
}