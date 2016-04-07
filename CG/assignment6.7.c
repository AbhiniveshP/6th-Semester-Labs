#include <GL/glut.h>

void Draw() {
	glClear(GL_COLOR_BUFFER_BIT);
	
	glBegin(GL_TRIANGLE_FAN);
	    glColor3f(1.0, 1.0, 1.0);
		glVertex3f(0.1, 0.2, 0.0);
        glVertex3f(0.3, 0.3, 0.0);
        glVertex3f(0.5, 0.4, 0.0);
        glColor3f(0.0, 0.0, 1.0);
        glVertex3f(0.5, 0.8, 0.0);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(0.8, 0.9, 0.0);
		
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
	glutInitWindowPosition(0, 0);
	glutCreateWindow("GL-TRIANGLE-FAN");
	
	glutDisplayFunc(Draw);
	glutMainLoop();
	return 0;
}