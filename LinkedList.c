//
//  LinkedList.c
//
//
//  Created by Varun on 15/01/17.
//
//

#include <stdio.h>
#include <stdlib.h>

struct LinkedList {
    
    int data;
    struct LinkedList *next;
};

void addAtEnd(struct LinkedList **q, int data)
{
    struct LinkedList *newNode, *lastNode;
    
    if (*q == NULL) {

        newNode = malloc(sizeof(struct LinkedList));
        newNode->data = data;
        newNode->next = NULL;
        *q = newNode;
    }
    else {
        lastNode = *q;
        
        while (lastNode->next != NULL) {
            lastNode = lastNode->next;
        }
        newNode = malloc(sizeof(struct LinkedList));
        newNode->data = data;
        newNode->next = NULL;
        lastNode->next = newNode;
    }
}

void addAtBeg(struct LinkedList **q, int data)
{
    struct LinkedList *newNode;
    
    newNode = malloc(sizeof(struct LinkedList));
    newNode->data = data;
    newNode->next = *q;
    *q = newNode;
    
}

int getCount(struct LinkedList *q)
{
    int count = 0;
    while (q != NULL) {
        count++;
        q = q->next;
    }
    return count;
}

void addAtIndex(struct LinkedList **q, int index, int data)
{
    struct LinkedList *newNode, *indexNode;
    int i = 0,count = getCount(*q);
    
    if (index >= count) {
        printf("Not enough nodes in linkedlist");
    }
    else if(index == count-1) {
        addAtEnd(q,data);
    }
    else if(index == 0) {
        addAtBeg(q,data);
    }
    else {
        indexNode = *q;
        
        while (1) {
            if (i == index - 1) {
                break;
            }
            i++;
            indexNode = indexNode->next;
        }
        newNode = malloc(sizeof(struct LinkedList));
        newNode->data = data;
        newNode->next = indexNode->next;
        indexNode->next = newNode;
    }
}

void display(struct LinkedList *q) {
    
    while (q != NULL) {
        printf("%d\t",q->data);
        q = q->next;
    }
    printf("\n");
}

int getSumOfData(struct LinkedList *q)
{
    int add=0;
    while(q != NULL)
    {
        add=add+(q->data);
        q=q->next;
    }
    return add;
}

void delLast(struct LinkedList **q)
{
    struct LinkedList *temp, *newLastNode;
    temp=*q;
    
    while(1)
    {
        if (temp->next == NULL) {
            break;
        }
        newLastNode = temp;
        temp=temp->next;
    }
    newLastNode->next = NULL;
    free(temp);
    
    return;
}

void delAtIndex(struct LinkedList **q,int index)
{
    int count,i=0;
    struct LinkedList *temp,*NewNextNode;
    count=getCount(*q);
    temp=*q;
    
    if(index>=count)
    {
         printf("not enough nodes in the linkedlist\n");
         return;
    }	
    if(count==1)
    {
        *q=NULL;
    }
    else
    {
        while(1)
        {
            if (i==index) {
                break;
            }
            NewNextNode = temp;
            temp=temp->next;
            i++;
        }
    }
    NewNextNode->next = temp->next;
    free(temp);
    
    return;
}

void reverse(struct LinkedList **x)
{
    struct LinkedList *q,*r,*s;
    q=*x;
    r=NULL;
    
    while(q!=NULL)
    {
        s=r;
        r=q;
        q=q->next;
        r->next=s;
    }
    *x=r;
}

void selectionSort(struct LinkedList *q)
{
    struct LinkedList *list1, *list2;
    int i,j,k,temp,n = getCount(q);
    list1 = q;
    
    for (i = 0; i < n-1;i++) {
        list2 = list1->next;
        for (j = i + 1; j < n ; j++) {
            if (list1->data > list2->data) {
                
                temp = list1->data;
                list1->data = list2->data;
                list2->data = temp;
            }
            list2 = list2->next;
        }
        list1 = list1->next;
    }
    return;
}

void bubbleSort(struct LinkedList *q)
{
    struct LinkedList *list1,*list2;
    int i,j,k,temp,n=getCount(q);

    k=n;
    for(i=0;i < n-1;i++,k--)
    {
        list1 = q;
        list2=list1->next;
        
        for(j=1;j<k;j++)
        {
            if(list1->data>list2->data)
            {
                temp=list1->data;
                list1->data=list2->data;
                list2->data=temp;
            }
            list1=list1->next;
            list2=list2->next;
        }
    }
    return;
}

int main() {
    
    struct LinkedList *start;
    int ad;
    start = NULL;
    
    addAtEnd(&start,59);

    addAtEnd(&start,23);

    addAtEnd(&start,47);
    
    addAtBeg(&start,11);

    //display(start);
    
    addAtEnd(&start,89);
    
    addAtEnd(&start,45);
    
    addAtIndex(&start,4,90);
    
    //display(start);
    
    //ad=getSumOfData(start);
    
    //printf("the sum of the data is %d\n",ad);
    
    //delLast(&start);

    //display(start);
    
    //ad=getSumOfData(start);
    //printf("the sum of the data is %d\n",ad);
    
    //delAtIndex(&start,3);
    
    //display(start);
    
    //reverse(&start);
    
    display(start);
    
    //selectionSort(start);

    //display(start);
    
    bubbleSort(start);
    
    display(start);


    return 0;
    
}
