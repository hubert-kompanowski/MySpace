#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
	int data;
	struct Node *next;
}lista;

int init(lista *s, int value)
{
	struct Node *head = s;
	s->data = value;
	s->next = NULL;
	return 0;
}

int append(lista *s, int data)
{
	struct Node *p , *new;
	p = s;
	while(p->next != NULL)
	{
		p = p->next;
	}
	new = malloc(sizeof(lista));
	new -> data = data;
	new->next = NULL;
	p->next = new;
	return 0;
}

int remove_last(lista *s)
{
	struct Node *p , *p1;
	p = s;
	p1 = s;
	while(p -> next != NULL)
	{
		p = p-> next;
	}
	while (s -> next != p)
	{
		s = s-> next;
	}
	s->next = NULL;
	free(p);
	return 0;
}
	
int remove_chosen(lista *s, int data)
{
	struct Node *p, *removed;
	p = s;
	removed = NULL;
	while(p->next != NULL)
	{
		if(p->data == data)
		{
			removed = p;
			break;
		}
	}
	if(removed = NULL)
	{
		return 1;
	}

}	
	
int print(lista *s)
{
	struct Node *start = s;
	while(start != NULL)
	{
		printf("%d\n", start -> data);
		start = start -> next;
	}
	return 0;
}

int main(void)
{
	lista b;
	lista *list = &b;
	int a = 5;
	init(list,a);
	append(list,6);
	append(list, 8);
	print(list);
	remove_last(list);
	print(list);
	
	
	return 0;
}

