/* RPN Simulator using shell window
 * by Muchen He
 * i@mansurhe.com
 */

// header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "CRPN.h"

// preprocessors
#define TRUE 1
#define FALSE 0

// global variables
struct stack * mainStack;

// main function
int main(void) {
  // first initialize the main stack
  initialize(mainStack);

  return 0;
}

// prints the stack out in a formatted manner
void printStack(struct stack * s) {

}
