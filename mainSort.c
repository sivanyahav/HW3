#include "isort.h"
#include <stdio.h>
#define N 50

int main()
{
    int arr [N]; int i=0;
    
    printf("Enter numbers to array");

    while(i<N)
    {
        int chosen;

        if(scanf("%d",&chosen)!=0)
        {

        *(arr+i)=chosen;
        i++;

        }
    }

    printf("\n");

    insertion_sort(arr,N);

    printf("[");
    for(int j=0; j<N-1;j++)
    {
        printf("%d , ",*(arr+j));
    }
    printf("%d]",*(arr+N-1));

    return 0;

}