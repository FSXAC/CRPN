/* RPN Simulator using shell window
 * by Muchen He
 * i@mansurhe.com
 */

// header file
#include "CRPN.h"

// global variables
struct stack * mainStack;

// main function
int main(void) {
  double a = 123.456;
  // first initialize the main stack
  mainStack = createNewStack();
  initialize(mainStack);

  // test
  push(mainStack, a);
  push(mainStack, 2.56);
  push(mainStack, 1);
  push(mainStack, 2);
  push(mainStack, 3);
  push(mainStack, 4);
  push(mainStack, 5);
  push(mainStack, 6);
  push(mainStack, 7);
  push(mainStack, 8);
  push(mainStack, 999);
  printStack(mainStack);

  getch();
  return 0;
}

// cretes a new stack
// RETURN: pointer to the new stack
struct stack * createNewStack() {
  struct stack * newStack = (struct stack *)malloc(sizeof(struct stack));
  return newStack;
}

// prints the stack out in a formatted manner
void printStack(struct stack * s) {
  int i = 0;
  double value_i;
  for (; i < MAX_HOLD; i++) {
    // get the number from the stack array first
    value_i = s->list[i - (MAX_HOLD - s->topIndex - 1)];

    printf("%2d: ", MAX_HOLD - i);

    // if the value from the array is not an emty value,
    if (MAX_HOLD - i - 1 <= s->topIndex) printf("%.4f\n", value_i);
    else printf("\n");
  }
}
