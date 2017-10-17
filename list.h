#ifndef INCLUDE_LIST
#define INCLUDE_LIST
#include <stdbool.h>
#include <setjmp.h>

jmp_buf Allocated_failed;

#define T List_T
typedef struct T* T;

extern T List_new();
extern void List_destroy(T* pls);
extern void List_add(T ls, void* elem);
extern void* List_remove(T ls);
extern int List_size(T ls);
extern bool List_isEmpty(T ls);

/*
extern void List_addFirst(T ls, void* elem);
extern void List_addLast(T ls, void* elem);
extern void List_addAll(T ls, T rls);
extern void* List_removeFirst(T ls);
extern void* List_removeLast(T ls);
*/
#undef T
#endif