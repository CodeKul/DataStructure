//
//  DSF.c
//  
//
//  Created by Varun on 25/02/17.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX 5

struct vertex
{
    char label;
    bool visited;
};

int stack[MAX];
int top=-1;

int adjMatrix[MAX][MAX];

int vertexCount=0;

struct vertex *lstVertex[MAX];

void push(int item)
{
    stack[++top]=item;
}

int pop()
{
    return stack[top--];
}

int peek()
{
    return stack[top];
}

bool isStackEmpty()
{
    return top==-1;
}

void addVertex(char label)
{
    struct vertex *vertex=(struct vertex*)malloc(sizeof(struct vertex));
    vertex->label=label;
    vertex->visited=false;
    lstVertex[vertexCount++]=vertex;
}

void addEdge(int start,int end)
{
    adjMatrix[start][end]=1;
    adjMatrix[end][start]=1;
}

int getAdjUnvisitedVertex(int vertexIndex)
{
    int i;
    
    for(i = 0; i<vertexCount; i++)
    {
        if(adjMatrix[vertexIndex][i] == 1 && lstVertex[i]->visited == false)
        {
            return i;
        }
    }
        return -1;
}

void displayVertex(int vertexIndex)
{
    printf("%c ",lstVertex[vertexIndex]->label);
}

void depthfirstsearch()
{
    int i = 0;
    lstVertex[0]->visited=true;
    
    displayVertex(0);
    
    push(0);
    
    while(!isStackEmpty())
    {
        int unvisitedVertex = getAdjUnvisitedVertex(peek());
        
        if(unvisitedVertex == -1)
        {
            pop();
        }
        else
        {
            lstVertex[unvisitedVertex]->visited = true;
            displayVertex(unvisitedVertex);
            push(unvisitedVertex);
        }
    }
    for(i = 0;i < vertexCount;i++)
    {
        lstVertex[i]->visited = false;
    }
    
    
    
}



int main()
{
    int i,j;
    for(i=0;i<MAX;i++)
    {
        for(j=0;j<MAX;j++)
        {
            adjMatrix[i][j]=0;
        }
    }
    
    addVertex('S');
    addVertex('A');
    addVertex('B');
    addVertex('C');
    addVertex('D');
    
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(0, 3);
    addEdge(1, 4);
    addEdge(2, 4);
    addEdge(3, 4);

    depthfirstsearch();
    
    printf("\n");
    return 0;


}











