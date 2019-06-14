#include <stdlib.h>
#include "assert.h"
#include "stack.h"
#include <stdio.h>

typedef struct _stack_t {
  stack_elem_t value;
  stack_t next;
}_stack_t;

stack_t stack_empty(){
  stack_t pointer = NULL;
  return pointer;
}

stack_t stack_push(stack_t s, stack_elem_t elem){
  stack_t aux = malloc(sizeof(_stack_t));
  aux -> value = elem;
  aux -> next = s;
  return aux;
}
//void* malloc(size_t bytes);
//void* calloc(size_t nitemS, size_t size);
//void* realloc(void* ptr, size_t size);
//void free(void* ptr);

stack_t stack_pop(stack_t s){
  assert( s != NULL );
  stack_t aux = s;
  s = s -> next;
  free(aux);
  return s;
}

unsigned int stack_size(stack_t s){
  unsigned int size = 0u;
  while (s != NULL) {
    s = s -> next;
    size++;
  }
  return size;
}

stack_elem_t stack_top(stack_t s){
  assert(s != NULL );
  return (s -> value);
}

bool stack_is_empty(stack_t s){
  return (s = NULL);
}

stack_elem_t *stack_to_array(stack_t s){
  unsigned int size = stack_size(s);
  stack_elem_t * array = calloc(size,sizeof(stack_elem_t)); // * array" to declarate arrays
  for (int i = size-1; i > -1; --i ){
    array[i] = s -> value;
    s = s -> next;
  }
  return array;
}


stack_t stack_destroy(stack_t s){
  stack_t aux;
  while (s != NULL) {
    aux = s -> next;
    free(s);
    s = aux;
  }
  return s;
}
