// https://minimin2.tistory.com/10?category=732990

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct listNode {
	element value;
	struct listNode* link;
}listNode;

void showListValue(listNode *head)
{	
	while (head != NULL)
	{
		printf("%d\n", head->value);
		head  = head ->link;
	}
}

int main(void)
{
	listNode* p1;
	listNode* p2;
	
	p1 = (listNode *)malloc(sizeof(listNode));
	p2 = (listNode *)malloc(sizeof(listNode));

	if (p1 == NULL || p2 == NULL)
		return -1;
	
	p1->value = 10;
	p1->link = p2;

	p2->value = 20;
	p2->link = NULL;

	showListValue(p1);

	free(p1);
	free(p2);

	return 0;
}