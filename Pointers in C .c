#include <stdio.h>
void update(int *a,int *b);

void update(int *a,int *b) {
int sum,sub;
sum=*a+*b;
sub=*b-*a;
*a=sum;
*b=abs(sub);
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;

    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}