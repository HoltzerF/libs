#include "stack.h"
#include <stdlib.h>
#include <string.h>

void stk_init(stack_t *s, unsigned int elem_size, unsigned int growth){
	s->memory = 0;
	s->max_elements = 0;
	s->num_elements = 0;
	s->elem_size = elem_size;
	s->growth = growth;
}

stack_t *stk_new(unsigned int elem_size, unsigned int growth){
	
	// allocate and initialize a stack object
	stack_t *s = malloc(sizeof(stack_t));
	if(s != 0){
		stk_init(s, elem_size, growth);
	}
	return s;
}

void stk_push(stack_t *s, void *data){
	
	// stack is full (or empty), increase in size
	if(s->max_elements <= s->num_elements){
		
		// growth the stack
		s->max_elements += s->growth;
		unsigned int size_in_bytes = s->max_elements * s->elem_size;
		
		// reallocate memory and set stack pointer
		s->memory = realloc(s->memory, size_in_bytes);
		s->ptr = s->memory + s->num_elements * s->elem_size;
		
		// error check, -> we lose data on error
		if(s->memory == 0){
			s->max_elements = 0;
			s->num_elements = 0;
			return;
		}
	}
	
	// actual pushing
	memcpy(s->ptr, data, s->elem_size);
	s->ptr += s->elem_size;
	++s->num_elements;
}

void stk_pop(stack_t *s, void *data){
	if(s->num_elements > 0){
		s->ptr -= s->elem_size;
		memcpy(data, s->ptr, s->elem_size);
		--s->num_elements;
	}
}

void stk_free(stack_t *s){
	if(s->max_elements > 0){
		free(s->memory);
		s->max_elements = 0;
	}
}

void stk_delete(stack_t *s){
	stk_free(s);
	free(s);
}
