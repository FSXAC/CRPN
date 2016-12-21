// header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// preprocessors
#define TRUE 1
#define FALSE 0

// global constants
#define MAX_HOLD 10

// stack type
struct stack {
  int topIndex;
  double * list;
};

// function prototypes
// struct stack
void initialize(struct stack * s);
int isStackEmpty(struct stack * s);
int isStackFull(struct stack * s);
int push(struct stack * s, double value);
int peek(struct stack * s, double * output);
int pop(struct stack * s, double * output);

// global functions
struct stack * createNewStack();
void printStack(struct stack * s);
double stringToDouble(char * string);

// calculator functions
int asmd(struct stack * s, int opertion);
