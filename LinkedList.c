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

void deleteLast(struct LinkedList **q,int index)
{
    int count=getCount(*q);
    if(index == count)
    {
        delLast(q);
    }
    else{
        while(i<=count)
        {
            
        }
        
    }
    
}

int main() {
    
    struct LinkedList *start;
    int ad;
    start = NULL;
    
    addAtEnd(&start,20);

    addAtEnd(&start,30);

    addAtEnd(&start,40);
    
    addAtBeg(&start,10);

    display(start);
    
    addAtEnd(&start,60);
    
    addAtEnd(&start,70);
    
    addAtIndex(&start,4,50);
    
    display(start);
    
    ad=getSumOfData(start);
    
    printf("the sum of the data is %d\n",ad);
    
    delLast(&start);

    display(start);
    
    ad=getSumOfData(start);
    printf("the sum of the data is %d\n",ad);

    return 0;
    
}
