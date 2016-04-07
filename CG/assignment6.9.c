#include <GL/glut.h>

void Draw() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUAD_STRIP);
		glVertex3f(0.0, 0.5, 0.0);
        //glVertex3f(0.2, 0.1, 0.0);
        glVertex3f(0.0, 0.3, 0.0);
        glColor3f(0.0, 0.0, 1.0);
        glVertex3f(0.3, 0.5, 0.0);
        glVertex3f(0.4, 0.3, 0.0);
        
        glVertex3f(0.8, 0.5, 0.0); 
        glVertex3f(0.6, 0.3, 0.0);
        
          
		
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
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("GL-QUADRILATERAL-STRIP");
	
	glutDisplayFunc(Draw);
	glutMainLoop();
	return 0;
}