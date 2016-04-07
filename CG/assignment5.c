#include <stdio.h>
#include <math.h>
#include <GL/glut.h>


// Center of the cicle = (320, 240)
int xc = 0, yc = 0;

// Plot eight points using circle's symmetrical property
void plot_point(int x, int y)
{
	int i;
	glBegin(GL_POINTS);
    for(i = 0; i < 200; i++){
    	//glVertex2i(i, 0);
    	//glVertex2i(0, i);
    	//glVertex2i(-i, 0);
    	glVertex2i(0, -i);
    }
	//glVertex2i(xc + x, yc + y);
	glVertex2i(xc + x, yc - y);
	//glVertex2i(xc + y, yc + x);
	//glVertex2i(xc + y, yc - x);
	glVertex2i(xc - x, yc - y);
	//glVertex2i(xc - y, yc - x);
	//glVertex2i(xc - x, yc + y);
	//glVertex2i(xc - y, yc + x);

	glVertex2i(50, -50);
	glVertex2i(-50, -50);
	glEnd();

}

// Function to draw a circle using midpoint's
// circle drawing algorithm
void mp_circle(int r)
{
	int x = 0, y = r;
	float h = (5.0 / 4.0) - r;

	/* Plot the points */
	/* Plot the first point */
	plot_point(x, y);
	
	/* Find all vertices till x=y -> second quadrant*/
	while (x < y)
	{
		if (h < 0)/*Select East*/
		h= h + 2 * x + 3;
		else/*Select South-East*/
		{
			h= h+ 2 * (x - y) + 5;
			y = y - 1;
		}
		x = x + 1;
		plot_point(x, y);
	}
	glFlush();
}

// Function to draw two concentric circles
void circle(void)
{
	/* Clears buffers to preset values */
	glClear(GL_COLOR_BUFFER_BIT);

	int radius1 = 100, radius2 = 200;
	//mp_circle(radius1);
	mp_circle(radius2);
}

void Init()
{
	/* Set clear color to white */
	glClearColor(0.0, 0.0, 0.0, 0);
	/* Set fill color to black */
	glColor3f(1.0, 1.0, 1.0);
	/* glViewport(0 , 0 , 640 , 480); */
	/* glMatrixMode(GL_PROJECTION); */
	/* glLoadIdentity(); */
	gluOrtho2D(-500, 500, -500, 500);
}

void main(int argc, char **argv)
{
	/* Initialise GLUT library */
	glutInit(&argc, argv);
	/* Set the initial display mode */
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	/* Set the initial window position and size */
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(640, 480);
	/* Create the window with title "CIRLCE USING MID-POINT ALGORITHM" */
	glutCreateWindow("SMILEY :-)");
	/* Initialize drawing colors */
	Init();
	/* Call the displaying function */
	glutDisplayFunc(circle);
	/* Keep displaying untill the program is closed */
	glutMainLoop();
}