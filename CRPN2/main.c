// header import files
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
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
  sscanf_s(string, "%lf", value);
}

// ***** CALCULATOR FUNCTIONS
int elementaryBinaryFunc(stack *s, int opcode) {
  double a, b;

  // check that there's at least 2 elements in stack
  if (s->topIndex >= 1) {
    pop(s, &a);
    pop(s, &b);
    switch (opcode) {
      case 0: push(s, b + a); break;
      case 1: push(s, b - a); break;
      case 2: push(s, b * a); break;
      case 3: push(s, b / a); break;
      case 4:
        push(s, a);
        push(s, b);
        break;
      default: break;
    }
    return TRUE;
  } else return FALSE;
}

int add(stack *s) {return elementaryBinaryFunc(s, 0);}
int minus(stack *s) {return elementaryBinaryFunc(s, 1);}
int mult(stack *s) {return elementaryBinaryFunc(s, 2);}
int divi(stack *s) {return elementaryBinaryFunc(s, 3);}
int swap(stack *s) {return elementaryBinaryFunc(s, 4);}

// ***** main function
int main(void) {
  // get characrter input
  char input;
  char *inputBuffer = (char *)malloc(sizeof(char) * 80);
  int inputPos = 0;

  // to stack
  double valueToStack;

  // temporary value
  double trash;

  // initialize main stack
  stack *mainStack = createNewStack();
  initialize(mainStack);
  printStack(mainStack);

  // get user input functions
  do {
    input = _getch();

    // look for type of input (number or function)
    if ((input >= '0' && input <= '9') || input == '.') {
      inputBuffer[inputPos++] = input;
      inputBuffer[inputPos]   = '\0';
    } else {
      // functions
      switch(input) {
        // add, sub, mult, div
        case '+': add(mainStack); break;
        case '-': minus(mainStack); break;
        case '*': mult(mainStack); break;
        case '/': divi(mainStack); break;

        // backspace
        case 8:
          if (inputPos == 0) pop(mainStack, &trash);
          else inputBuffer[--inputPos] = '\0';
          break;

        // arrow keys
        case -32:
          switch(_getch()) {

            // swap
            case 77:
              swap(mainStack); break;
            default: break;
          }
          break;

        // enter
        case 13:
          // check for valid items to push
          if (inputPos != 0) {
            stringToDouble(inputBuffer, &valueToStack);
            push(mainStack, valueToStack);

            // reset input buffer
            inputBuffer[0] = '\0';
            inputPos       = 0;
          }
          break;
        default: printf("invalid input\n"); break;
      }
    }

    // display
    printStack(mainStack);
    printf("%s", inputBuffer);
  } while (1);

  return 0;
}
