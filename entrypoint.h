#ifndef ENTRYPOINT_H
#define ENTRYPOINT_H

#include "appcontext.h"

enum Operation
{
    ValidateInput,
    ConvertValue
};

void doOperation(Operation operation, AppContext* context);

#endif
