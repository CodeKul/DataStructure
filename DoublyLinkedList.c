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

int getCount(struct List *q)
{
	int i=0;
	while(q != NULL)
	{
		q=q->next;
		i++;
	}
	return i;
	
}

void addAtBeg(struct List **q,int num)
{
    struct List *temp;
	if(*q == NULL)
	{
		temp=malloc(sizeof(struct List));
		temp->data=num;
		temp->next=NULL;
		temp->prev=NULL;
		(*q)=temp;
		
	}
	else
	{
		temp=malloc(sizeof(struct List));
		temp->data=num;
		temp->next=*q;
		temp->prev=NULL;
		(*q)->prev=temp;
		(*q)=temp;		
	}
}

void addAtIndex(struct List **q,int loc,int num)
{

	int count,i=1;
	struct List *temp,*s; 

	count=getCount(*q);

	if(loc>count)
	{
		printf("inside getcount");
		printf("Their are not enough nodes in the linked list\n");
		return;

	}
	if(loc==0)
	{
		addAtBeg(q,num);
        	return;     
	}
	if(loc==count)
	{
		addAtEnd(q,num);
		return;
	}
	s=*q;
	while(i<loc)
	{
		s = s->next;
		i++;
	}

	temp=malloc(sizeof(struct List));
	temp->data=num;
	temp->next=s;
	temp->prev=s->prev;
	(s->prev)->next=temp;
	s->prev=temp;
}

void delAtIndex(struct List **q,int loc)
{
	int count,i=1;
        struct List *temp,*s; 

	count=getCount(*q);

	if(loc>count)
	{
		printf("inside getcount");
		printf("Their are not enough nodes in the linked list\n");
		return;
	}
	if(loc==1)
	{
		*q==NULL;
		return;
	}
	if(loc==count)
	{
		temp=*q;
		while(temp->next !=NULL)
		{
			temp=temp->next;
		}
		(temp->prev)->next=NULL;
		return;
        }
	s=*q;
	while(i<loc)
	{
		s=s->next;
		i++;
  	}
	(s->prev)->next=s->next;
	(s->next)->prev=s->prev;
	free(s);
}

int getSumOfData(struct List *q)
{
	int sum=0;
	while(q != NULL)	
	{
		sum=sum+(q->data);
		q=q->next;
	}
	return sum;
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
    	int y,z;
    
	addAtEnd(&start,12);
	addAtEnd(&start,34);
	addAtEnd(&start,39);
	addAtEnd(&start,79);
	addAtEnd(&start,19);
    
	display(start);
	//y=getCount(start);
	// printf("the total nodes are %d",y);
  	addAtBeg(&start,78);    
   	display(start);

    	addAtIndex(&start,3,67);
   	display(start);

	delAtIndex(&start,2);
	display(start);
	
	z=getSumOfData(start);
	printf("sum=%d\n",z);

}
