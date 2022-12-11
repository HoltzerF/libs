#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <string.h>

typedef struct{
	void *memory;			// pointer to dynamic stack memory
	int allocated_elements;	// how many elements fit into allocated memory pointed to by memory
	
	int elements;			// number of elements on the stack
	int elem_size;			// the size of one stack element
	
	char *ptr;				// the stack pointer used for push and pop
	int growth;				// how much the stack grows after beeing filled
}stack_t;

/* creates a new stack object
*/
stack_t *stk_new(unsigned int elem_size, int growth);

/* initializes a stack
*/
void stk_init(stack_t *s, unsigned int elem_size, int growth);

/* push data onto stack
*/
void stk_push(stack_t *s, void *data);

/* pop data from stack
*/
void stk_pop(stack_t *s, void *data);

/* free allocated memory of an stack
*/
void stk_free(stack_t *s);

/* deletes an allocated stack object
*/
void stk_delete(stack_t *s);

#endif
