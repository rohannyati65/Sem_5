#include<windows.h>

#include<GL\glew.h>

#include<GL\glut.h>

#include <stdio.h>





int  x,y,r,xc,yc;







void display()

{

    glColor3f(1.0, 0.0, 0.0);  //Quadrant Plot Graph
    glPointSize(3.0);
    glBegin(GL_LINES);

    glVertex2i(-50, 0);

    glVertex2i(50, 0);

    glVertex2i(0, -50);

    glVertex2i(0, 50);

    glEnd();
    glColor3f(0.0, 1.0, 0.0);

    glBegin(GL_POINTS);


    int d[r];
    d[0]=1-r;
    x=0,y=0;
    y=r;
    if(d[0]<=0)
    {

        glVertex2i(xc + x, yc + y);

    glVertex2i(xc + x, yc - y);

    glVertex2i(xc + y, yc + x);

    glVertex2i(xc + y, yc - x);

    glVertex2i(xc - x, yc - y);

    glVertex2i(xc - y, yc - x);

    glVertex2i(xc - x, yc + y);

    glVertex2i(xc - y, yc + x);
        d[1]=d[0]+2*x+1;
        x=x+1;
    }
    else
    {

       glVertex2i(xc + x, yc + y);

    glVertex2i(xc + x, yc - y);

    glVertex2i(xc + y, yc + x);

    glVertex2i(xc + y, yc - x);

    glVertex2i(xc - x, yc - y);

    glVertex2i(xc - y, yc - x);

    glVertex2i(xc - x, yc + y);

    glVertex2i(xc - y, yc + x);
        d[1]=d[0]+2*x+3-2*y;
        x=x+1;
        y=y-1;
    }
    int i=1;
    for(; i<y; i++)
    {
        if(d[i]<=0)
        {
            glVertex2i(xc + x, yc + y);

    glVertex2i(xc + x, yc - y);

    glVertex2i(xc + y, yc + x);

    glVertex2i(xc + y, yc - x);

    glVertex2i(xc - x, yc - y);

    glVertex2i(xc - y, yc - x);

    glVertex2i(xc - x, yc + y);

    glVertex2i(xc - y, yc + x);
            d[i+1]=d[i]+2*x+1;
            x=x+1;
        }
        else
        {
            glVertex2i(xc + x, yc + y);

    glVertex2i(xc + x, yc - y);

    glVertex2i(xc + y, yc + x);

    glVertex2i(xc + y, yc - x);

    glVertex2i(xc - x, yc - y);

    glVertex2i(xc - y, yc - x);

    glVertex2i(xc - x, yc + y);

    glVertex2i(xc - y, yc + x);
            d[i+1]=d[i]+2*x+3-2*y;
            x=x+1;
            y=y-1;
        }
    }

    glEnd();

    glFlush();

}

void init()

{

    glClearColor(0.7, 0.7, 0.7, 0.7);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluOrtho2D(-50, 50, -50, 50);

}

int main(int argc, char* argv[])
{


    printf("Enter the coordinates of the circle's centre:");

    scanf("%d  %d",&xc,&yc);

    printf("Enter the value of r : ");

    scanf("%d",&r);

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

    glutInitWindowSize(500, 500);

    glutInitWindowPosition(100, 100);

    glutCreateWindow("Bresenham Circle");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

}
