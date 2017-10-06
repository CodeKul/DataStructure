//
//  BinarySearch.c
//  
//
//  Created by Codekul on 27/02/17.
//
//
#include<stdio.h>
#define MAX 9

int arr[MAX]={12,23,34,45,56,67,78,89,90};
int midpoint=-1,startpoint=0,endpoint=MAX-1;



int BinarySearch(int data)
{
    int index=-1;
    while(startpoint<=endpoint)
    {
        midpoint=(startpoint + endpoint)/2;
        if(arr[midpoint]==data)
        {
            index=midpoint;
            return index;
        }
        else
        {
            if(arr[midpoint]<data)
            {
                startpoint=midpoint+1;
            }
            else
            {
                endpoint=midpoint-1;
            }
        }
    }
        return index;
}

void display()
{
    int i;
    for(i=0;i<MAX;i++)
    {
        printf("%d\t",arr[i]);
    }
}



int main()
{
    int location;
    
    display();
    location=BinarySearch(34);
    
    if(location==-1)
    {
        printf("thers no such number present inside the array\n");
    }
    else
    {
    printf("the number %d is found at %d location\n",arr[location],location);
    }
    return 0;
}

