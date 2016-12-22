// header import files
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// preprocessors
#define TRUE  1
#define FALSE 0

// stack definition - representation using linked list
// struct node {
//   double value;
//   struct node *next;
// };

// stack definition - representation using array
#define MAX_SIZE 10
typedef struct {
  int topIndex;
  double * list;
} stack;

// ***** stack ADT functions
// initialize an empty stack
void initialize(stack *s) {
  s->topIndex = -1;
  s->list = (double *)malloc(sizeof(double) * MAX_SIZE);
}

// check if a stack is empty
int isStackEmpty(stack *s) {
  return (s->topIndex == -1);
}

// cehck if stack is full
int isStackFull(stack *s) {
  return (s->topIndex == MAX_SIZE-1);
}

// push, add an element into the stack
int push(stack *s, double value) {
  // check for availability
  if (!isStackFull(s)) {
    s->topIndex++;
    s->list[s->topIndex] = value;
    return TRUE;
  } else return FALSE;
}

// peek at an item top of stack
int peek(stack *s, double *output) {
  if (!isStackEmpty(s)) {
    *(output) = s->list[s->topIndex];
    return TRUE;
  } else return FALSE;
}

// pop an item from the stack
int pop(stack *s, double *output) {
  if (peek(s, output)) {
    s->topIndex--;
    return TRUE;
  } else return FALSE;
}

// ***** OPERATION functions
// create new stack
stack * createNewStack() {
  stack *newStack = (stack *)malloc(sizeof(stack));
  return newStack;
}

// print stack in a user friendly way
void printStack(stack * s) {
  int i = 0;
  double value_i;
  system("cls");
  for (; i < MAX_SIZE; i++) {
    value_i = s->list[i - (MAX_SIZE - s->topIndex - 1)];
    printf("%d: ", MAX_SIZE - i);
    if (MAX_SIZE - i - 1 <= s->topIndex)
      printf("%.4f\n", value_i);
    else
      printf("\n");
  }
}

// parse string into double
void stringToDouble(char *string, double *value) {
  sscanf_s(string, "%f", value);
}
