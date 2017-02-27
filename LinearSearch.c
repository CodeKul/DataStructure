//
//  Searching.c
//  
//
//  Created by Varun on 27/02/17.
//
//

#include <stdio.h>
#define MAX 9

int arr[MAX]={12,23,34,45,56,67,78,89,90};

void display(int *arr)
{
    int i=0;
    for(i=0;i<MAX;i++)
    {
        printf("%d\t",arr[i]);
    }
}

int find(int data)
{
    int index=-1;
    int comparisons=0,i=0;
    
    for(i=0;i<MAX;i++)
    {
        
        comparisons++;
        if(data==arr[i])
        {
            index=i;
            return index;
        }
    }
    return index;
}



int main()
{
    int location;
    printf("input array\n");
    display(arr);
    
    location=find(56);
    
    if(location==-1)
    {
        printf("element not found");
    }
    else{
        printf("the no. %d found at %d in the array\n",arr[location],location);
    }
    return 0;
}
