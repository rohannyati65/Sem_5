#include<windows.h>

#include<GL\glew.h>

#include<GL\glut.h>

#include <stdio.h>


int  x,y,rx,ry,xc,yc;

void display()

{

    glColor3f(1.0, 0.0, 0.0);  //Quadrant Plot Graph

    glBegin(GL_LINES);

    glVertex2i(-50, 0);

    glVertex2i(50, 0);

    glVertex2i(0, -50);

    glVertex2i(0, 50);

    glEnd();
    glBegin(GL_POINTS);
    glColor3f(1.0,0.0,0.0);
    glPointSize(5.0);

    x=0;
    y=ry;
    float p=ry*ry-rx*rx*ry-(rx*rx)/4;
    while(2*ry*ry*x <=2*rx*rx*y)
    {
        if(p < 0)
        {
            x++;
            p = p+2*ry*ry*x+ry*ry;
        }
        else
        {
            x++;
            y--;
            p = p+2*ry*ry*x-2*rx*rx*y-ry*ry;
        }
        glPointSize(5.0);
        glVertex2i(xc+x,yc+y);
        glVertex2i(xc+x,yc-y);
        glVertex2i(xc-x,yc+y);
        glVertex2i(xc-x,yc-y);

        printf("%.2f, %.2f \n",(xc+x),(yc+y));
        printf("%.2f, %.2f \n",(xc+x),(yc-y));
        printf("%.2f, %.2f \n",(xc-x),(yc+y));
        printf("%.2f, %.2f \n",(xc-x),(yc-y));

    }
    float p2=ry*ry*(x+0.5)*(x+0.5)+rx*rx*(y-1)*(y-1)-rx*rx*ry*ry;
    while(y > 0)
    {
        if(p2 <= 0)
        {
            x++;
            y--;
            p2 = p2+2*ry*ry*x-2*rx*rx*y+rx*rx;
        }
        else
        {
            y--;
            p2 = p2-2*rx*rx*y+rx*rx;
        }
        glPointSize(5.0);
        glVertex2i(xc+x,yc+y);
        glVertex2i(xc+x,yc-y);
        glVertex2i(xc-x,yc+y);
        glVertex2i(xc-x,yc-y);

        printf("%.2f, %.2f \n",(xc+x),(yc+y));
        printf("%.2f, %.2f \n",(xc+x),(yc-y));
        printf("%.2f, %.2f \n",(xc-x),(yc+y));
        printf("%.2f, %.2f \n",(xc-x),(yc-y));
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

    printf("Enter the coordinates of the ellipse centre:");

    scanf("%d  %d",&xc,&yc);

    printf("Enter the value of rx : ");

    scanf("%d",&rx);
    printf("Enter the value of ry : ");

    scanf("%d",&ry);

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

    glutInitWindowSize(500, 500);

    glutInitWindowPosition(100, 100);

    glutCreateWindow("Midpoint Ellipse");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

}
