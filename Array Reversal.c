#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr, i;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }


      int temp;
    for (i=0; i<num-1; i++) {
    for(int j=i+1;j<num;j++)
    {
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
    }

    for(i = 0; i < num; i++)
        printf("%d ", *(arr + i));
    return 0;
}