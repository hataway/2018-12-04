#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int value;
	struct node *next;
};
typedef struct node list;
typedef list * Head;

Head append(Head head, int input)
{
	Head nextnode = head;
	Head cur = (Head)malloc(sizeof(list));
	cur->value = input;
	cur->next = NULL;

	if (head == NULL)
	{
		head = cur;
		return head;
	}

	while (nextnode->next != NULL)
	{
		nextnode = nextnode->next;
	}
	nextnode->next = cur;
	return head;
}

void reprint(Head head, int cnt)
{
	Head reverse = head;
	printf("입력자료 역순 : ");

	for (int i = cnt; i > 0; i--)
	{
		for (int j = i - 1; j > 0; j--)
		{
			reverse = reverse->next;
		}
		printf("%d ", reverse->value);
		reverse = head;
	}
	printf("\n");
}

void midprint(Head head, int cnt)
{
	Head mid = head;

	if (cnt % 2 == 1)
	{
		for (int i = cnt; i > (cnt + 1) / 2; i--)
		{
			mid = mid->next;
		}
		printf("중간위치 값 : %d\n", mid->value);
	}

	else
	{
		for (int i = cnt; i > (cnt + 2) / 2; i--)
		{
			mid = mid->next;
		}
		printf("중간위치 값 : %d ", mid->value);
		mid = mid->next;
		printf("%d\n", mid->value);
	}
}

void printlist(Head head)
{
	Head nextnode = head;
	while (nextnode != NULL)
	{
		printf("%d ", nextnode->value);
		nextnode = nextnode->next;
	}
	printf("\n");
}

void odddel(Head head, int cnt)
{
	Head node = NULL;
	Head temp = head;
	for (int i = 0; i < cnt / 2; i++)
	{
		node = NULL;
		temp = head;

		for (int j = 0; j < i; j++)
		{
			temp = temp->next;
			if (i == 0)
				temp = head;
		}
		node = temp;
		temp = temp->next;
		node->next = temp->next;
		free(temp);
	}
}

int main(void)
{
	Head head = NULL;
	int input = 0, cnt = 0;
	while (scanf("%d", &input) != EOF)
	{
		head = append(head, input);
		cnt++;
	}
	printf("입력된 자료의 개수 : %d\n", cnt);
	reprint(head, cnt);
	midprint(head, cnt);
	printf("입력자료 입력 순 : ");
	printlist(head);
	odddel(head, cnt);
	printf("홀수번째 삭제 : ");
	printlist(head);
	return 0;
}