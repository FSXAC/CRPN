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
  // first initialize the main stack
  mainStack = createNewStack();
  initialize(mainStack);

  // test
  push(mainStack, 1.55);
  push(mainStack, 2.56);
  printStack(mainStack);

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
    value_i = s->list[MAX_HOLD - i - 1];

    printf("%2d: ", MAX_HOLD - i);

    // if the value from the array is not an emty value,
    if (!isnan(value_i)) printf("%.4f\n", value_i);
    else printf("\n");
  }
}
