#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {


char s[1000];
int freq;
scanf("%s",s);
for(int i=48;i<58;i++){
    freq=0;
for(int j=0;j<strlen(s);j++)
{
    if(s[j]==i)
    freq++;
}
printf("%d ",freq);
}

    return 0;
}
