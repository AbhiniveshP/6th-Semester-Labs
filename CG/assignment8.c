#include <stdio.h>
#include <string.h>
#include <math.h>
#include <GL/glut.h>
#include <GL/glu.h>

char n[20];
void decimal()
{
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2d(-5,0);
	glVertex2d(5,0);
	glVertex2d(5,10);
	glVertex2d(-5,10);
	glEnd();
}
void segment_one(int i,int j)
{
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2d(j*(10+25+(i*110)),0);
	glVertex2d(j*(5+25+(i*110)),5);
	glVertex2d(j*(10+25+(i*110)),10);
	glVertex2d(j*(-10+125+(i*110)),10);
	glVertex2d(j*(-5+125+(i*110)),5);
	glVertex2d(j*(-10+125+(i*110)),0);
	glEnd();
}

void segment_two(int i,int j)
{
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2d(j*(10+25+(i*110)),10);
	glVertex2d(j*(10+25+(i*110)),90);
	glVertex2d(j*(5+25+(i*110)),95);
	glVertex2d(j*(25+(i*110)),90);
	glVertex2d(j*(25+(i*110)),10);
	glVertex2d(j*(5+25+(i*110)),5);
	glEnd();
}

void segment_three(int i,int j)
{
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2d(j*(-10+125+(i*110)),10);
	glVertex2d(j*(-10+125+(i*110)),90);
	glVertex2d(j*(-5+125+(i*110)),95);
	glVertex2d(j*(125+(i*110)),90);
	glVertex2d(j*(125+(i*110)),10);
	glVertex2d(j*(-5+125+(i*110)),5);
	glEnd();
}

void segment_four(int i,int j)
{
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2d(j*(-10+125+(i*110)),90);
	glVertex2d(j*(-5+125+(i*110)),95);
	glVertex2d(j*(-10+125+(i*110)),100);
	glVertex2d(j*(10+25+(i*110)),100);
	glVertex2d(j*(5+25+(i*110)),95);
	glVertex2d(j*(10+25+(i*110)),90);
	glEnd();
}

void segment_five(int i,int j)
{
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2d(j*(10+25+(i*110)),100);
	glVertex2d(j*(10+25+(i*110)),180);
	glVertex2d(j*(5+25+(i*110)),185);
	glVertex2d(j*(25+(i*110)),180);
	glVertex2d(j*(25+(i*110)),100);
	glVertex2d(j*(5+25+(i*110)),95);
	glEnd();
}

void segment_six(int i,int j)
{
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2d(j*(-10+125+(i*110)),100);
	glVertex2d(j*(-5+125+(i*110)),95);
	glVertex2d(j*(125+(i*110)),100);
	glVertex2d(j*(125+(i*110)),180);
	glVertex2d(j*(-5+125+(i*110)),185);
	glVertex2d(j*(-10+125+(i*110)),180);
	glEnd();
}

void segment_seven(int i,int j)
{
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2d(j*(-10+125+(i*110)),180);
	glVertex2d(j*(-5+125+(i*110)),185);
	glVertex2d(j*(-10+125+(i*110)),190);
	glVertex2d(j*(10+25+(i*110)),190);
	glVertex2d(j*(5+25+(i*110)),185);
	glVertex2d(j*(10+25+(i*110)),180);
	glEnd();
}

void draw()
{
	int i=0,j=0;
	char a[5],b[5];
	while(i<5)
	{
		if(n[i] == '.')
			break;
		a[i]=n[i];
		i++;
	}
	i++;
	while(i<strlen(n))
	{
		b[j]=n[i];
		j++;
		i++;
	}
	glClear(GL_COLOR_BUFFER_BIT);
	if(strlen(b) != 0)
		decimal();
	i=strlen(a)-1;
	j=i;
	while(i>=0)
	{
		if(a[i]=='0')
		{
			segment_one(j-i,-1);
			segment_two(j-i,-1);
			segment_three(j-i,-1);
			segment_five(j-i,-1);
			segment_six(j-i,-1);
			segment_seven(j-i,-1);
		}
		else if(a[i]=='1')
		{
			segment_two(j-i,-1);
			segment_five(j-i,-1);
		}
		else if(a[i]=='2')
		{
			segment_one(j-i,-1);
			segment_three(j-i,-1);
			segment_four(j-i,-1);
			segment_five(j-i,-1);
			segment_seven(j-i,-1);
		}
		else if(a[i]=='3')
		{
			segment_one(j-i,-1);
			segment_two(j-i,-1);
			segment_four(j-i,-1);
			segment_five(j-i,-1);
			segment_seven(j-i,-1);
		}
		else if(a[i]=='4')
		{
			segment_two(j-i,-1);
			segment_four(j-i,-1);
			segment_five(j-i,-1);
			segment_six(j-i,-1);
		}
		else if(a[i]=='5')
		{
			segment_one(j-i,-1);
			segment_two(j-i,-1);
			segment_four(j-i,-1);
			segment_six(j-i,-1);
			segment_seven(j-i,-1);
		}
		else if(a[i]=='6')
		{
			segment_one(j-i,-1);
			segment_two(j-i,-1);
			segment_three(j-i,-1);
			segment_four(j-i,-1);
			segment_six(j-i,-1);
			segment_seven(j-i,-1);
		}
		else if(a[i]=='7')
		{
			segment_two(j-i,-1);
			segment_five(j-i,-1);
			segment_seven(j-i,-1);
		}
		else if(a[i]=='8')
		{
			segment_one(j-i,-1);
			segment_two(j-i,-1);
			segment_three(j-i,-1);
			segment_four(j-i,-1);
			segment_five(j-i,-1);
			segment_six(j-i,-1);
			segment_seven(j-i,-1);
		}
		else if(a[i]=='9')
		{
			segment_one(j-i,-1);
			segment_two(j-i,-1);
			segment_four(j-i,-1);
			segment_five(j-i,-1);
			segment_six(j-i,-1);
			segment_seven(j-i,-1);
		}
		i--;
	}
	i=strlen(b);
	while(i>=0)
	{
		if(b[i]=='0')
		{
			segment_one(i,1);
			segment_two(i,1);
			segment_three(i,1);
			segment_five(i,1);
			segment_six(i,1);
			segment_seven(i,1);
		}
		else if(b[i]=='1')
		{
			segment_three(i,1);
			segment_six(i,1);
		}
		else if(b[i]=='2')
		{
			segment_one(i,1);
			segment_two(i,1);
			segment_four(i,1);
			segment_six(i,1);
			segment_seven(i,1);
		}
		else if(b[i]=='3')
		{
			segment_one(i,1);
			segment_three(i,1);
			segment_four(i,1);
			segment_six(i,1);
			segment_seven(i,1);
		}
		else if(b[i]=='4')
		{
			segment_three(i,1);
			segment_four(i,1);
			segment_five(i,1);
			segment_six(i,1);
		}
		else if(b[i]=='5')
		{
			segment_one(i,1);
			segment_three(i,1);
			segment_four(i,1);
			segment_five(i,1);
			segment_seven(i,1);
		}
		else if(b[i]=='6')
		{
			segment_one(i,1);
			segment_two(i,1);
			segment_three(i,1);
			segment_four(i,1);
			segment_five(i,1);
			segment_seven(i,1);
		}
		else if(b[i]=='7')
		{
			segment_three(i,1);
			segment_six(i,1);
			segment_seven(i,1);
		}
		else if(b[i]=='8')
		{
			segment_one(i,1);
			segment_two(i,1);
			segment_three(i,1);
			segment_four(i,1);
			segment_five(i,1);
			segment_six(i,1);
			segment_seven(i,1);
		}
		else if(b[i]=='9')
		{
			segment_one(i,1);
			segment_three(i,1);
			segment_four(i,1);
			segment_five(i,1);
			segment_six(i,1);
			segment_seven(i,1);
		}
		i--;
	}
	glFlush();
}

void init()
{
	glClearColor(0.0,0.0,0.0,0.0);
	gluOrtho2D(-650,650,-100,500);
}

void main(int argc,char**argv)
{
	scanf("%s",n);	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(1300,600);
	glutCreateWindow("SEVEN_SEGMENT_DISPLAY");
	init();
	draw();
	glutMainLoop();
}