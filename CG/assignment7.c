
#include <math.h>
#include <GL/glut.h>

void LineDDA(void)
{

	
	glClear(GL_COLOR_BUFFER_BIT);
	/* Plot the points */
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.45, 0.0);
	glVertex2i(0, 480);
	glVertex2i(720, 480);
	glVertex2i(720, 320);
	glVertex2i(0, 320);
	glEnd();
	glLineWidth(5);
	glBegin(GL_LINE_LOOP);

	glColor3f(0.0, 0.0, 1.0);
	float r = 80;
	int j;
	int num_segments = 3000;
	float theta, x, y;
	for (j = 0; j < num_segments; j++)
	{
		theta = 2.0f * 3.1415926f * (j) / (num_segments);//get the current angle 

		x = r * cosf(theta);//calculate the x component 
		y = r * sinf(theta);//calculate the y component 

		glVertex2f(x + 360, y + 240);//output vertex 

	}
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.39, 0.0);
	glVertex2i(0, 0);
	glVertex2i(720, 0);
	glVertex2i(720, 160);
	glVertex2i(0, 160);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 1.0);
	theta = 0;
	int i;
	for (i = 0; i<24; i++)
	{
		theta = 2.0f * 3.1415926f * (i) / 24;
		x = r * cosf(theta);//calculate the x component 
		y = r * sinf(theta);//calculate the y component 
		glVertex2i(360, 240);
		glVertex2i(x + 360, y + 240);
	}
	glEnd();

	glFlush();
}
void Init()
{
	/* Set clear color to white */
	glClearColor(1.0, 1.0, 1.0, 0);
	/* Set fill color to black */

	/* glViewport(0 , 0 , 640 , 480); */
	/* glMatrixMode(GL_PROJECTION); */
	/* glLoadIdentity(); */
	gluOrtho2D(0, 720, 0, 480);
}
void main(int argc, char **argv)
{
	// printf("Enter two end points of the line to be drawn:\n");
	// printf("\n************************************");
	// printf("\nEnter Radius(R):\n");
	// scanf("%lf",&R);
	// printf("\n************************************");
	// printf("\nEnter Point1( X2 , Y2):\n");
	// scanf("%lf%lf",&X2,&Y2);

	/* Initialise GLUT library */
	glutInit(&argc, argv);
	/* Set the initial display mode */
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	/* Set the initial window position and size */
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(600, 400);
	/* Create the window with title "DDA_Line" */
	glutCreateWindow("INDIAN FLAG");
	/* Initialize drawing colors */
	Init();
	/* Call the displaying function */
	glutDisplayFunc(LineDDA);
	/* Keep displaying untill the program is closed */
	glutMainLoop();
}