#include<windows.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
float x1,x2,y1,y2;

void display(void)
{
float dy,dx,x,y,D_initial,dD,D_new;
dx=x2-x1;
dy=y2-y1;

D_initial = 2*(dy) - dx ;
dD = 2*(dy) - 2*(dx);

x=x1;
y=y1;
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();

for (int x=x1 ; x<=x2 ; x++)
{
    if(D_initial<0){
        y = y;
        D_new = D_initial + 2*(dy) ;
        D_initial = D_new;
    }
    if(D_initial>=0){
        y= y + 1;
        D_new = D_initial + dD ;
        D_initial = D_new;
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
glutCreateWindow ("Mid Point Line Algo");
init();
glutDisplayFunc(display);
glutMainLoop();

return 0;
}
