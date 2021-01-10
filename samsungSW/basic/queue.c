// https://minimin2.tistory.com/9?category=732990

#include <stdio.h>
#define MAX_SIZE	1000
#define TRUE		1
#define FALSE		0

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

int isEmpty(int* queue)
{
	if (front == rear)
		return TRUE;

	else
		return FALSE;
}

int isFull(int* queue)
{
	int tmp = (rear+1) % MAX_SIZE;
	
	if (tmp == front)
		return TRUE;

	else
		return FALSE;
}

int enqueue(int* queue, int value)
{
	if (isFull(queue) == TRUE)
		return -1;

	else
	{
		queue[++rear] = value;

		return value;
	}
}

int dequeue(int* queue)
{
	if (isEmpty(queue) == TRUE)
		return -1;

	else
	{
		front = (front + 1) % MAX_SIZE;
		return queue[front];
	}
}

void initQueue(int* queue)
{
	front = -1;
	rear = -1;
	memset(queue, 0, sizeof(queue));
}

int main(void)
{
	initQueue(&queue);

	enqueue(&queue, 5);
	enqueue(&queue, 1);

	printf("%d\n", dequeue(&queue));
	printf("%d\n", dequeue(&queue));
	printf("%d\n", dequeue(&queue));

	return 0;
}