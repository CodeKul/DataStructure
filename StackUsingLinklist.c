//
//  StackUsingLinklist.c
//  
//
//  Created by Codekul on 03/02/17.
//
//

#include <stdio.h>


struct stack
{
    int data;
    struct stack* top;
};

void push(struct stack **q,int d)
{
    struct stack* temp;
    
    temp=(struct stack *)malloc(sizeof(struct stack));
    
    if(temp==NULL)
    {
        printf("stack is Full\n");
        return;
    }
    temp->data=d;
    temp->top=*q;
    *q=temp;
}

void pop(struct stack **q)
{
    struct stack* temp;
    if(*q==NULL)
    {
        printf("stack is empty\n");
        return;
    }
    temp=*q;
    (*q)=(*q)->top;
    free(temp);
}
    

void display(struct stack *q)
{
    struct stack *temp;
    if(q==NULL)
    {
        printf("stack is empty\n");
        return;
    }
    while(q != NULL)
    {
        temp=q;
        q=q->top;
        printf("%d\n",temp->data);
    }
}

void delete(struct stack **q)
{
    struct stack *temp;
    if(*q==NULL)
    {
        printf("stack is empty\n");
        return;
    }
    while(*q != NULL)
    {
        temp=*q;
        (*q)=(*q)->top;
        free(temp);
    }
}

int main()
{
    struct stack *start=NULL;
    
    push(&start,34);
    
    push(&start,44);
    
    push(&start,54);

    
    
    pop(&start);
    
    pop(&start);
    
     display(start);





}
