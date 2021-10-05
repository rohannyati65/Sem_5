#include<windows.h>
#include<stdio.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdlib.h>

int Xmax,Xmin,Ymax,Ymin,x,y;

void init_gl(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);

	glColor3f(1.0, 1.0, 1.0);

	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(-100,100,-100,100);
}

void display()
{

	glPointSize(4.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);

    if(Xmin < x && x < Xmax && Ymin < y && y < Ymax){
		glColor3f(1.0, 0.0, 0.0);
		printf("inside %d %d\n", x, y);
	}
	else{
		glColor3f(0.0, 0.0, 1.0);
		printf("outside %d %d\n", x, y);
	}

	glVertex2i(x, y);

	glEnd();

	glPointSize(1.0);
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_LINE_LOOP);

		glVertex2i(Xmin, Ymin);
		glVertex2i(Xmin, Ymax);
		glVertex2i(Xmax, Ymax);
		glVertex2i(Xmax, Ymin);

	glEnd();
	glFlush();
}

int main (int argc, char** argv)
{
    printf("Enter the value of Xmin : ");
    scanf("%d",&Xmin);
    printf("Enter the value of Ymin : ");
    scanf("%d",&Ymin);
    printf("Enter the value of Xmax : ");
    scanf("%d",&Xmax);
    printf("Enter the value of Ymax : ");
    scanf("%d",&Ymax);
	printf("Enter the random point x and y :");
	scanf("%d%d",&x,&y);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100,100);

	glutCreateWindow(*argv);
	init_gl();

	glutDisplayFunc(display);
	glutMainLoop();
}
