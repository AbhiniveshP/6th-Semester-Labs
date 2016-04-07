#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <unistd.h>

float r=50;

void draw_circle(int t)
{
	int i;
	glClear(GL_COLOR_BUFFER_BIT);
	float x,y,h,d_se,d_e;
	x=0;
	y=r;
	h=1-r;
	d_e=3;
	d_se=5-(2*r);
	glColor3f(0.101, 0.0, 1.0);
	glBegin(GL_POINTS);
	glVertex2d(x,y+t);
	glVertex2d(y,x+t);
	glVertex2d(-x,-y+t);
	glVertex2d(-y,-x+t);
	glVertex2d(y,-x+t);
	glVertex2d(-x,y+t);
	glVertex2d(-y,x+t);
	glVertex2d(x,-y+t);
	while(y>x)
	{
		if(h<0) // East point
		{
			h=h+d_e;
			d_se+=2;
			d_e+=2;
		}
		else
		{
			h=h+d_se;
			d_se+=4;
			d_e+=2;
			y=y-1;
		}
		x=x+1;
		glVertex2d(x,y+t);
		glVertex2d(y,x+t);
		glVertex2d(-x,-y+t);
		glVertex2d(-y,-x+t);
		glVertex2d(y,-x+t);
		glVertex2d(-x,y+t);
		glVertex2d(-y,x+t);
		glVertex2d(x,-y+t);
	}
	glEnd();
	float ang;
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(0,t);
	for(i=0;i<=360;i++)
	{
		ang = (((3.14)*i)/180);
		glVertex2f((r*sin(ang)),(r*cos(ang))+t);
	}
	glEnd();
	glFlush();
}

void draw()
{
	int t=0,i=1,j;
	while(i==1)
	{
		while(t<200)
		{
			draw_circle(t);
			sleep(0.001);
			t++;
		}
		while(t>-200)
		{
			draw_circle(t);
			sleep(0.001);
			t--;
		}
	}
}

void init()
{
	glClearColor(0.0,0.0,0.0,0.0);
	gluOrtho2D(-600,600,-300,300);
}

void main(int argc,char**argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(1200,600);
	glutCreateWindow("BOUNCING BALL");
	init();
	draw();
	glutMainLoop();
}