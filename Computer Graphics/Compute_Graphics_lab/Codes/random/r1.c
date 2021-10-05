#include<stdlib.h>
#include<stdio.h>

void display(float x1,float y1, float x2, float y2)
{
float dy,dx,step,x,y,k,m;
dx=x2-x1;
dy=y2-y1;
m=dx/dy;

if(abs(dx)> abs(dy))
{
step = abs(dx);
}
else
step = abs(dy);

x= x1;
y=y1;

for (k=1 ;k<=step;k++)
{
    if(m<1){
        x= 1 + x;
        y= m + Y;
    }
    if(m==1){
        x= 1 + x;
        y= 1 + Y;
    }
    if(m>1){
        x= (1/m) + x;
        y= 1 + Y;
    }
    cout<<x<<y<<endl;
}
}

int main() {
printf("Enter the value of x1 : ");
scanf("%f",&x1);
printf("Enter the value of y1 : ");
scanf("%f",&y1);
printf("Enter the value of x2 : ");
scanf("%f",&x2);
printf("Enter the value of y2 : ");
scanf("%f",&y2);
display(x1,y1,x2,y2);
return 0;
}
