#ifndef INCLUDE_LIST
#define INCLUDE_LIST
#include <stdbool.h>
#include <setjmp.h>

jmp_buf Allocated_failed;

#define T List
#define E List_Iterator

typedef struct T* T;
typedef struct E* E;

extern T List_new();
extern void List_destroy(T* pls);
extern void List_add(T ls, void* elem);
extern void* List_remove(T ls);
extern int List_size(T ls);
extern bool List_isEmpty(T ls);
extern E List_begin(T ls);
extern E List_end(T ls);

//through
extern void List_forEach(T ls, void(*f)(void* elem));

/*
extern void List_addFirst(T ls, void* elem);
extern void List_addLast(T ls, void* elem);
extern void List_addAll(T ls, T rls);
extern void* List_removeFirst(T ls);
extern void* List_removeLast(T ls);
*/

//iterator method
extern void LstIt_getNext(E it);
extern void* LstIt_getValue(E it);
extern bool LstIt_equalTo(E lv, E rv);
void LstIt_destory(E* it);


#undef T
#endif

