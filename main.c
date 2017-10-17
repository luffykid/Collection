#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
	List_T ls = List_new();

	for (int i = 0; i < 10; i++) {
		int * elem = (int*)malloc(sizeof(int));
		scanf_s("%d", elem);
		List_add(ls, elem);
	}

	while (!List_isEmpty(ls)) {
		int* elem = List_remove(ls);
		printf("%d\n", *elem);
	}
	system("pause");
	return 0;
}
