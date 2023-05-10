#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n,digit;
    scanf("%d", &n);

    int sum=0;
    while (n !=0) {
        digit =n%10;
        n/=10;
    sum+=digit;
    }
    printf("%d",sum);
    return 0;
}
