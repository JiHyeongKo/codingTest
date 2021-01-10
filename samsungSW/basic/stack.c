// https://minimin2.tistory.com/3

#include <stdio.h>
#define MAX_SIZE	1000
#define TRUE		1
#define FALSE		0

int stack[MAX_SIZE];
int top = -1;	// ¸Ç À§´Â ÇÑ Ä­ 

int isEmpty(int *stack)
{
	if (top == -1)
		return TRUE;

	else
		return FALSE;
}

int isFull(int* stack)
{
	if (top >= MAX_SIZE-1)
		return TRUE;

	else
		return FALSE;
}

int push(int *stack, int value)
{
	if (isFull == TRUE)
		return -1;

	else
	{
		stack[++top] = value;

		return value;
	}

}

int pop(int *stack)
{
	if (isEmpty == TRUE)
		return -1;

	else
		return stack[top--];
}

void initStack(int* stack)
{
	top = -1;
	memset(stack, 0, sizeof(stack));
}

int main(void)
{
	initStack(&stack);

	push(&stack, 5);
	push(&stack, 1);

	printf("%d\n", pop(&stack));
	printf("%d\n", pop(&stack));
	printf("%d\n", pop(&stack));

	return 0;
}