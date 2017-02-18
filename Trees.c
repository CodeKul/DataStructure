//
//  Trees.c
//  
//
//  Created by Varun on 16/02/17.
//
//

#include <stdio.h>
#include <stdlib.h>

struct treeNode
{
    struct treeNode *left;
    struct treeNode *right;
    int data;
};

void insert(struct treeNode **q,int d)
{
    if(*q == NULL)
    {
        *q=malloc(sizeof(struct treeNode));
        (*q)->left=NULL;
        (*q)->data=d;
        (*q)->right=NULL;
    }
    else
    {
        if(d<((*q)->data))
        {
            insert(&((*q)->left),d);
        }
        else
        {
            insert(&((*q)->right),d);
        }
    }
}

void inorder(struct treeNode *tn)
{
    if(tn==NULL)
    {
        return;
    }
    inorder(tn->left);
    printf("%d\t",tn->data);
    inorder(tn->right);
}

void preorder(struct treeNode *tn)
{
    if(tn==NULL)
    {
        return;
    }
    printf("%d\t",tn->data);
    preorder(tn->left);
    preorder(tn->right);
}

void postorder(struct treeNode *tn)
{
    if(tn==NULL)
    {
        return;
    }
    postorder(tn->left);
    postorder(tn->right);
    printf("%d\t",tn->data);
}

int main()
{
    struct treeNode *tn;
    int i;
    
    tn=NULL;
    
    int arr[]={40,20,10,30,60,80,90};
    
    for(i=0;i<7;i++)
    {
        insert(&tn,arr[i]);
    }
    
    printf("inorder\n");
    inorder(tn);
    printf("\n");

    printf("preorder\n");
    preorder(tn);
    printf("\n");
    
    printf("postorder\n");
    postorder(tn);
    printf("\n");

}
