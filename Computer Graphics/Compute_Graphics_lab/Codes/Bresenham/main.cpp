#include<windows.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
float x1,x2,y1,y2;

void display(void)
{
float dy,dx,step,x,y,pk;
dx=x2-x1;
dy=y2-y1;

pk = 2*(dy) - dx ;

step = dx-1 ;

x=x1;
y=y1;
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();

for (int k=1 ;k<=step;k++)
{
    if(pk<0){
        pk=pk + 2*(dy) ;
        x = x + 1;
        y = y;
    }
    if(pk>=0){
        pk=pk + 2*(dy) - 2*(dx) ;
        x= x + 1;
        y= y + 1;
    }

glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();
}

glFlush();
}

void init(void)
{
glColor3f(1.0,0.0,0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-100,100,-100,100);
}

int main(int argc, char** argv) {
printf("Enter the value of x1 : ");
scanf("%f",&x1);
printf("Enter the value of y1 : ");
scanf("%f",&y1);
printf("Enter the value of x2 : ");
scanf("%f",&x2);
printf("Enter the value of y2 : ");
scanf("%f",&y2);

glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (100,100);
glutCreateWindow ("DDA Line Algo");
init();
glutDisplayFunc(display);
glutMainLoop();

return 0;
}
