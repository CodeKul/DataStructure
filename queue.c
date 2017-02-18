#include<stdio.h>

struct node
{
	int data;
	struct node  *next;
};

struct queue
{
	struct queue *front;
	struct queue *rear;
};

void initqueue(struct queue *q)
{
	q->front=NULL;
	q->rear=NULL;
}

void AddInQueue(struct queue *q,int d)
{
	struct queue *temp;
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
		q->rear=q->front=NULL;
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
		printf("\nqueue is empty\n");
		return;
	}
	
	temp=q->front;
	q->front=q->front->next;
	free(temp);	
}

void display(struct queue *q)
{
	if(q->rear == NULL)
	{
		printf("\nqueue is empty\n");
		return;
	}
	while(q->front != q->rear)
	{
		q->front=q->front->rear;
		printf("\n%d",q->front->data);
	}
}

void deleteQueue(struct queue *q)
{
	struct node *temp;
	if(q->rear == NULL)
	{
		printf("\nqueue is empty\n");
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

	display(&q);

	RemoveFromQueue(&q);
	RemoveFromQueue(&q);
	RemoveFromQueue(&q);
		
	display(&q);	
}

