#include "CRPN.h"

// Initialize a stack instance
// PARAM: stack * s - the stack to initialize
void initialize(struct stack * s) {
  s->topIndex = -1;
  s->list = (double *)malloc(sizeof(double) * MAX_HOLD);
}

// Checks if a stack is empty
// PARAM: stack * s - the stack to check
// RETURN: 1 - empty, 0 - not empty
int isStackEmpty(struct stack * s) {
  return (s->topIndex == -1);
}

// Checks if a stack is full
// PARAM: stack * s - the stack to check
// RETURN: 1 - full, 0 - not full
int isStackFull(struct stack * s) {
  return (s->topIndex == MAX_HOLD-1);
}

// push / insert an item into the stack, LIFO
// PARAM: stack * s - the stack to add to
// PARAM: float value - the value to add
// RETURN: 1 for success, 0 for exception
int push(struct stack * s, double value) {
  // check if the stack is full
  if (!isStackFull(s)) {
    s->topIndex++;
    s->list[s->topIndex] = value;
    return TRUE;
  } else return FALSE;
}

// get the last value from stack
// PARAM: stack * s - the stack to check
// RETURN: the value of the last item from stack
//         return NULL if stack is empty
int peek(struct stack * s) {
  // checking if the stack is empty first
  if (!isStackEmpty(s)) return s->list[s->topIndex];
  else return NULL;
}

// get the last value from stack AND delete it
// PARAM: stack * s - the stack to check
// RETURN: the value of the last item from stack
//         return NULL if stack is empty
int pop(struct stack * s) {
  int value = peek(s);

  // if the stack is empty, then decrease topindex by 1
  if (value != NULL) s->topIndex--;

  return value;
}
