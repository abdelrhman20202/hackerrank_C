#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{ int x,y;
float z,j;
scanf("%d %d", &x, &y);
scanf("%f %f", &z, &j);
int sum=x+y;
int difference=x-y;
float sumf=z+j;
float differencef=z-j;
printf("%d %d\n",sum,difference);
printf("%.1f %.1f",sumf,differencef);    
    return 0;
}
