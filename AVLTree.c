//
//  AVLTree.c
//  
//
//  Created by Varun on 23/02/17.
//
//

#include <stdio.h>
#define TRUE 1
#define FALSE 0

struct AVLNode
{
    int data;
    struct AVLNode *left;
    struct AVLNode *right;
    int balFact;
};

void BuildTree(struct AVLNode **q,int d,int *h)
{
    struct AVLNode node1,node2;
    
    if(*q == NULL)
    {
        *q=(struct AVLNode *)malloc(sizeof(struct AVLNode));
        *q->data=d;
        *q->left=NULL;
        *q->right=NULL;
        *q->balFact=0;
        *h=true;
    }
    
    if(data<(*q->data))
    {
        *q->left=BuildTree(*q->left,d,h);
        if(*h)
        {
            switch(*q->balFact)
            {
                case 1:
                    node1=*q->left;
                    if(node1->balFact == 1)
                    {
                        *q->left=node1->right;
                        node1->right=*q;
                        *q=node1;
                        *q->balFact=0;
                    }
                    else
                    {
                        node2=node1->right;
                        node1->right=node2->left;
                        node2->left=node1;
                        *q->left=node2->right;
                        node2->right=*q;
                        
                        if(node2->balfact==1)
                        {
                            *q->balFact=-1;
                        }
                        else
                        {
                            *q->balFact=0;
                        }
                        
                        if(node2->balfact==-1)
                        {
                            node1->balFact=1;
                        }
                        else
                        {
                            node1->balFact=0;
                        }
                        *q=node2;
                    }
                    *q->balFact=0;
                    *h=FALSE;
                    break;
                    
                    
                case 0:
                    *q->balFact=1;
                    break;
                case -1:
                    *q->balFact=0;
                    *h=FALSE;
                    break;
            }
        }
        return *q;
    }
    
    if(data>(*q->data))
    {
        *q->right=BuildTree(*q->right,d,h);
        if(*h)
        {
            switch(*q->balFact)
            {
                case 1:
                    *q->balFact=0;
                    *h=FALSE;
                    break;
                case 0:
                    *q->balFact=-1;
                case -1:
                    
            }
        }
    }
    
}


int main()
{
    struct AVLNode *avl=NULL;
    int h;
    
    
    
}
