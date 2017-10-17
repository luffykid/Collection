#include "list.h"
#include <assert.h>
#include <stdlib.h>

#define T List_T



typedef struct T {
	int size;
	struct Node_T {
		void* elem;
		struct Node_T* front;
		struct Node_T* back;
	}head;
}*T;

typedef struct Node_T* N;

static N Node_new(void* elem) {
	N node = (N)malloc(sizeof(*node));
	if (!node) longjmp(Allocated_failed, 2);

	node->elem = elem;
	return node;
}

static void Node_destroy(N* pn) {
	assert(pn && *pn);
	free(*pn);
	*pn = NULL;
}

static void Node_insert(N fn, N bn) {
	bn->back = fn->back;
	bn->front = fn;

	fn->back->front = bn;
	fn->back = bn;
}

static void* Node_delete(N node) {
	node->back->front = node->front;
	node->front->back = node->back;

	return node->elem;
}

T List_new() {
	T ls = (T)malloc(sizeof(*ls));
	if (!ls) longjmp(Allocated_failed, 1);

	ls->size = 0;
	ls->head.front = ls->head.back = &ls->head;
	return ls;
}

void List_destroy(T* pls) {
	assert(pls && *pls);

	N it = NULL;
	while ((it = (*pls)->head.back) != &(*pls)->head) {
		Node_delete(it);
		Node_destroy(&it);
	}

	free(*pls);
	*pls = NULL;
}

void List_add(T ls, void* elem) {
	assert(ls);

	N node = Node_new(elem);
	Node_insert(&ls->head, node);
	ls->size++;
}

void* List_remove(T ls) {
	assert(ls && ls->size);

	N node = ls->head.back;
	void* elem = node->elem;
	Node_delete(node);
	Node_destroy(&node);
	ls->size--;

	return elem;
}

int List_size(T ls) {
	return ls->size;
}

bool List_isEmpty(T ls) {
	return ls->size == 0;
}
