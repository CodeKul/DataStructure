//
//  DoublyLinkedList.c
//  
//
//  Created by Varun on 24/01/17.
//
//

#include <stdio.h>
#include<stdlib.h>
struct List {
    
    struct List *prev;
    int data;
    struct List *next;
};

void addAtEnd(struct List **q, int d) {
    struct List *temp,*r;
    if(*q == NULL)
    {
        temp=malloc(sizeof(struct List));
        temp->data=d;
        temp->next=NULL;
        temp->prev=NULL;
        *q=temp;
    }
    else
    {
        temp=*q;
        while(1)
        {
            if (temp->next == NULL) {
                break;
            }
            temp=temp->next;
        }
        r=malloc(sizeof(struct List));
        r->data=d;
        r->next=NULL;
        r->prev=temp;
        temp->next=r;
    }
}

void display(struct List *q)
{
    while(q != NULL)
    {
        printf("%d\t",q->data);
        q=q->next;
    }
    printf("\n");

}
int main() {
    
    struct List *start = NULL;
    
    addAtEnd(&start,12);
     addAtEnd(&start,34);
    
    display(start);
    
}
