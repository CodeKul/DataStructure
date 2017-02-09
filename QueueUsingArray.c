//
//  QueueUsingArray.c
//  
//
//  Created by Codekul on 03/02/17.
//
//

#include <stdio.h>

#define MAX 5

struct queue
{
    int arr[5];
    int front;
    int rear;
};

void initQueue(struct queue *s)
{
    s->front=0;
    s->rear=0;
}

void addToQueue(struct queue *s,int d)
{
    if(s->rear==4)
    {
        printf("Queue is full\n");
        return;
    }
    s->arr[s->rear]=d;
    (s->rear)++;
}

void removeFromQueue(struct queue *s)
{
    if(s->rear==0)
    {
        printf("Queue is empty\n");
        return;
    }
    s->front++;
}

void display(struct queue *s)
{
    int i;
    if(s->rear==0)
    {
        printf("Queue is empty\n");
        return;
    }
    for(i=(s->front);i<(s->rear);i++)
    {
        printf("%d\t",s->arr[i]);
    }
    printf("\n");
}


int main()
{
    struct queue q;
    
    initQueue(&q);
    
    addToQueue(&q,23);
    display(&q);
    addToQueue(&q,67);
    display(&q);
    addToQueue(&q,45);
    
    display(&q);
    
    removeFromQueue(&q);
    display(&q);
    removeFromQueue(&q);
    
    display(&q);
    
    
}
