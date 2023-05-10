#include <stdio.h>
int max_of_four(int x, int y, int z, int j);

int max_of_four(int x, int y, int z, int j)
{   int max;
    if (x>y &&  x>z && x>j)
    {
        max= x;
    }
 else if ( x<y && y>z && y>j) 
    {
 max= y;
    }  
     else if ( x<z && y<z && z>j) 
    {
max= z;
    } 
     else if ( x<j && j>z && y<j) 
    {
 max= j;
    } 
    return max;   
}
int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}
