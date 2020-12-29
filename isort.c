#include <stdio.h>
#include "isort.h"


void swap(int *x , int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

void shift_element(int* arr, int i)
{
    for(int j=0; j<i; j++)
    {
        swap(arr+j, arr+j+1);
    }
}

void insertion_sort(int* arr , int len)
{

    for (int i = 1; i < len; i++)
     {

    int curr = *(arr+i); //arr+step
    int j = i - 1;

    /**Compare current with each element on the left of it until an element smaller than
    it is found.
    For descending order, change key<array[j] to key>array[j].
    */

    while (curr < *(arr+j) && j >= 0)
     {

        swap(arr+j+1, arr+j);

         --j;
    }
    
    *(arr+j + 1) = curr;
    }
}
