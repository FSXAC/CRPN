#include "CRPN.h"

// adds the bottom two numbers in the stack together
// PARAM: struct stack * s - the stack we do our operations ons
// RETURN: 1 if the calcuation is successful, 0 if unsuccessful
int asmd(struct stack * s, int opertion) {
  double a, b, sum; 

  // at least 2 numbers in the stack
  if (s->topIndex >= 1) {
    pop(s, &a);
    pop(s, &b);
    switch (opertion) {
    case 0:
      push(s, a + b);
      break;
    case 1:
      push(s, b - a);
      break;
    case 2:
      push(s, a * b);
      break;
    case 3:
      push(s, b / a);
      break;
    case 4: // swap
      push(s, a);
      push(s, b);
      break;
    default:
      break;
    }
    return TRUE;
  } else return FALSE;
}