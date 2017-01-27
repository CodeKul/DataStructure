//
//  StacksUsingArrays2.c
//  
//
//  Created by Varun on 27/01/17.
//
//

#include <stdio.h>

#define MAX 5

struct stack
{
    int arr[MAX];
    int top;
};

void initStack(struct stack *s)
{
    s->top = 0;
}

void push(struct stack *s,int d)
{
    if(s->top == MAX)
    {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[s->top]=d;
    s->top++;
    return;
}

void pop(struct stack *s)
{
    if(s->top == 0)
    {
        printf("stack underflow\n");
        return;
    }
    s->top--;
    return;
}

void display(struct stack s)
{
    int i;
    if(s->top == 0)
    {
        printf("stack is empty\n");
        return;
    }

    for(i=0;i<s.top;i++)
    {
        printf("%d\t",s.arr[i]);
    }
    printf("\n");
    return;
}


int main()
{
    struct stack s;
    
    initStack(&s);
    
    push(&s,10);
    
    push(&s,20);
    
    push(&s,30);
    
    push(&s,40);
    
    push(&s,50);
    
    push(&s,70);
    
    push(&s,80);
    
    display(s);
    
    pop(&s);
    
    pop(&s);
    
    pop(&s);
    
    pop(&s);
    
    pop(&s);
    
    pop(&s);
    
    display(s);
    
    return 0;
}
