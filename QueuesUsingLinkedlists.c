//
//  QueuesUsingLinkedlists.c
//  
//
//  Created by Varun on 06/02/17.
//
//

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node  *next;
};

struct queue
{
    struct node *front;
    struct node *rear;
};

void initqueue(struct queue *q)
{
    q->front=NULL;
    q->rear=NULL;
}

void AddInQueue(struct queue *q,int d)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    
    if(temp == NULL)
    {
        printf("queue is full\n");
        return;
    }
    
    temp->data=d;
    temp->next=NULL;
    
    if(q->front == NULL)
    {
        q->rear = q->front = temp;
        return;
    }
    
    q->rear->next=temp;
    q->rear=q->rear->next;
}

void RemoveFromQueue(struct queue *q)
{
    struct node *temp;
    
    if(q->rear == NULL)
    {
        printf("queue is empty\n");
        return;
    }
    temp=q->front;
    if (q->front == q->rear) {
        q->front = q->rear = NULL;
    }
    else {
        q->front=q->front->next;
    }
    free(temp);
}

void displayData(struct queue *q)
{
    struct node *tempFront = q->front;
    struct node *tempRear = q->rear;

    if(q->rear == NULL)
    {
        printf("queue is empty\n");
        return;
    }
    while(1)
    {
        printf("%d\t",tempFront->data);
        if (tempFront == tempRear) {
            break;
        }
        tempFront=tempFront->next;
    }
    printf("\n");
}

void deleteQueue(struct queue *q)
{
    struct node *temp;
    if(q->rear == NULL)
    {
        printf("queue is empty\n");
        return;
    }
    while(q->front!=NULL)
    {
        temp=q->front;
        q->front=q->front->next;
        free(temp);
    }
}

int main()
{
    struct queue q;
    
    initqueue(&q);
    
    AddInQueue(&q,23);
    AddInQueue(&q,34);
    AddInQueue(&q,45);

    displayData(&q);
    
    RemoveFromQueue(&q);
    RemoveFromQueue(&q);
    displayData(&q);

    RemoveFromQueue(&q);
    
    displayData(&q);
}

