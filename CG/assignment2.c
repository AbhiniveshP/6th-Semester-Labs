#include<stdio.h>

#include<GL/glut.h>



/* Function to plot a point */
void setPixel(GLint x, GLint y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

/* Midpoint Line Algorithm */
void mp_line(int x1, int y1, int x2, int y2)
{
	int dx, dy, x, y, d,de,dne;

	dx = (x2 - x1);
	dy = (y2 - y1);
	de = 2*dy;
	dne = 2 * (dy - dx);
	
	/* Set the initial decision parameter and the initial point */
	d = 2 * dy - dx;
	x = x1;
	y = y1;

	while(x<x2)
	{
		setPixel(x, y);
		if (d <= 0)/*select EAST*/
		{
			d = d + de;
		}
		else /*Select NORTH-EAST*/
		{
			d = d + dne;
			y = y + 1;
		}
		x = x + 1;
	}
	glFlush();
}


void draw(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	

	/* 1 */
	mp_line(0, 0, 250, 250);

	glFlush();
}

void init() {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(240, 300);
	glutCreateWindow("LINE--MIDPOINT LINE ALGORITHM");
	glClearColor(0.0, 0.0, 0.0, 0);
	glColor3s(1.0, 1.0, 1.0);
	gluOrtho2D(0, 640, 0, 480);

}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	init();
	glutDisplayFunc(draw);
	glutMainLoop();
	return 0;
}
