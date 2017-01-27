//
//  StacksUsingArray.c
//  
//
//  Created by Varun on 27/01/17.
//
//

#include <stdio.h>

#define MAX_CAPACITY 10

int top = 0;
int stack[MAX_CAPACITY];

void push(int d) {
    
    if (top == MAX_CAPACITY) {
        printf("Overflow\n");
        return;
    }
    stack[top++] = d;
    return;
}

void pop() {
    if (top == 0) {
        printf("Underflow");
        return;
    }
    top--;
    return;
}

void display() {
    
    int i = 0;
    if (top == 0) {
        printf("stack is empty");
        return;
    }

    for (i = 0; i<top; i++) {
        printf("%d\t",stack[i]);
    }
    printf("\n");
    return;
}

int main() {
    
    push(10);
    
    push(20);
    
    display();
    
    push(30);
    
    push(40);
    
    display();
    
    pop();
    
    display();
    
    push(40);

    display();

    push(50);

    display();

    push(60);

    display();

}
