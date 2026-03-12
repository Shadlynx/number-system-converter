#ifndef LOGIC_H
#define LOGIC_H

#include "appcontext.h"

#define DECIMAL_BASE 10
#define BINARY_BASE 2
#define OCTAL_BASE 8

#define INT_BIT_COUNT 32
#define MAX_BINARY_INPUT_LENGTH 32
#define MAX_OCTAL_INPUT_LENGTH 11

#define DECIMAL_OUTPUT_BUFFER_SIZE 50
#define BINARY_OUTPUT_BUFFER_SIZE 33
#define OCTAL_OUTPUT_BUFFER_SIZE 12

void validateInput(AppContext* context);
void parseInput(AppContext* context);
void convertValue(AppContext* context);

#endif
