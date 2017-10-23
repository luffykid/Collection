#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "list.h"

typedef struct elem {
	int i;
	int j;
}elem, *pelem;
/*
int main() {
	Stack_T stk = Stack_new();
	for (int i = 0; i < 10; i++) {
		int * elem = (int*)malloc(sizeof(int));
		scanf_s("%d", elem);
		Stack_push(stk, elem);
	}
	while (!Stack_empty(stk)) {
		int* elem = Stack_pop(stk);
		printf("%d\n", *elem);
	}
	system("pause");
	return 0;
}*/

void f(int* elem) {
	*elem *= 1000;
}

int main() {
	List ls = List_new();
	FILE *in = fopen("in.txt", "r");

	for (int i = 0; i < 10; i++) {
		int * elem = (int*)malloc(sizeof(int));
		fscanf_s(in, "%d", elem);
		List_add(ls, elem);
	}
	List_forEach(ls, f);
	while (!List_isEmpty(ls)) {
		int* elem = List_remove(ls);
		printf("%d\n", *elem);
	}


	system("pause");
	return 0;
}
