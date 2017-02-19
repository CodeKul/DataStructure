//
//  Trees.c
//  
//
//  Created by Varun on 16/02/17.
//
//

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

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

void search(struct treeNode **q1,struct treeNode **x1,struct treeNode **parent,int num,int *found)
{
    struct treeNode *q2;
    q2=*q1;
    *found=FALSE;
    *parent=NULL;
    
    while(q2 != NULL)
    {
        if(q2->data == num)
        {
            *found=TRUE;
            *x1=q2;
            return;
        }
        *parent=q2;
        
        if(num>(q2->data))
        {
            q2=q2->right;
        }
        else
        {
            q2=q2->left;
        }
    }
}

void delete(struct treeNode **q,int num)
{
    int found;
    struct treeNode *x,*parent,*xsucc;
    
    if(*q == NULL)
    {
        printf("the tree is empty\n");
    }
    
    parent=x=NULL;
    
    search(q,&x,&parent,num,&found);
    
    if(found == FALSE)
    {
        printf("The data node not found\n");
        return;
    }
    
    if (parent == NULL) {
        if(x->left != NULL && x->right != NULL)
        {
            parent=x;
            xsucc=x->right;
            x=x->left;

            while(x->right != NULL)
            {
                x=x->right;
            }
            x->right = xsucc;
            *q = parent->left;
            free(parent);
            return;
        }
        
        if(x->left == NULL && x->right == NULL)
        {
            *q=NULL;
            free(x);
            printf("there is no node in the tree");
            return;
        }
        
        if(x->left == NULL && x->right != NULL)
        {
            printf("right not NULL\nleft not NULL\n");
            parent=x;
            x=x->right;
            *q=x;
            free(parent);
            return;
        }
        if(x->left != NULL && x->right == NULL)
        {
            parent=x;
            x=x->left;
            *q=x;
            free(parent);
            return;
        }
    }
    
    if(x->left != NULL && x->right != NULL)
    {
        parent=x;
        xsucc=x->right;
        
        while(xsucc->left != NULL)
        {
            parent=xsucc;
            xsucc=xsucc->left;
        }
        
        x->data=xsucc->data;
        x=xsucc;
    }
    

    if(x->left != NULL && x->right == NULL)
    {
        if(parent->left == x)
        {
            parent->left = x->left;
        }
        if(parent->right == x)
        {
            parent->right = x->right;
        }
        free(x);
        return;
    }
    
    if(x->left == NULL && x->right == NULL)
    {
        if(parent->left == x)
        {
            parent->left=NULL;
        }
        if(parent->right == x)
        {
            parent->right=NULL;
        }
        free(x);
        return;
    }
    
    if(x->left == NULL && x->right != NULL)
    {
        if(parent->left == x)
        {
            parent->left=x->right;
        }
        if(parent->right == x)
        {
            parent->right=x->right;
        }
        free(x);
        return;
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
    
    int arr[]={40,20,10,30};
    
    for(i=0;i<4;i++)
    {
        insert(&tn,arr[i]);
    }
    
    printf("inorder\n");
    inorder(tn);
    printf("\n");

    //printf("preorder\n");
    //preorder(tn);
    //printf("\n");
    
    //printf("postorder\n");
    //postorder(tn);
    //printf("\n");
    
//    delete(&tn,10);
//    delete(&tn,30);
//    delete(&tn,60);
//    inorder(tn);

//    delete(&tn,80);
//    delete(&tn,90);
//    delete(&tn,20);
//    inorder(tn);
    
    
    delete(&tn,40);

    inorder(tn);
    printf("\n");
    preorder(tn);
    printf("\n");

}
