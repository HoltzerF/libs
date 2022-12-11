#include "stack.h"

static void stk_alloc(stack_t *s){
	
	// allocate new memory if we have a growth
	if(s->growth > 0){
		// allocate memory for a new stack size
		s->allocated_elements += s->growth;
		s->memory = realloc(s->memory, s->allocated_elements * s->elem_size);
	}
	
	// change states on error
	if(s->memory == 0){
		s->allocated_elements = 0;
		s->elements = 0;
	}
}

void stk_init(stack_t *s, unsigned int elem_size, int growth){
	s->elem_size = elem_size;
	s->growth = growth;
	s->allocated_elements = 0;
	s->elements = 0;
	s->memory = 0;
	
	// setting up memory pointers
	stk_alloc(s);
	s->ptr = s->memory;
}

stack_t *stk_new(unsigned int elem_size, int growth){
	
	// allocate and initialize a stack object
	stack_t *s = malloc(sizeof(stack_t));
	if(s != 0){
		stk_init(s, elem_size, growth);
	}
	return s;
}

void stk_push(stack_t *s, void *data){
	if(s->allocated_elements == s->elements){
		stk_alloc(s);
	}
	if(s->allocated_elements > s->elements){
		memcpy(s->ptr, data, s->elem_size);
		s->ptr += s->elem_size;
		++s->elements;
	}
}

void stk_pop(stack_t *s, void *data){
	if(s->elements > 0){
		s->ptr -= s->elem_size;
		memcpy(data, s->ptr, s->elem_size);
		--s->elements;
	}
}

void stk_free(stack_t *s){
	if(s->allocated_elements > 0){
		free(s->memory);
	}
}

void stk_delete(stack_t *s){
	stk_free(s);
	free(s);
}
