#include "entrypoint.h"
#include "logic.h"

void doOperation(Operation operation, AppContext* context)
{
    switch (operation)
    {
    case ValidateInput:
        validateInput(context);
        break;
    case ConvertValue:
        validateInput(context);

        if (!context->hasError)
        {
            parseInput(context);

            if (!context->hasError)
            {
                convertValue(context);
            }
        }
        break;
    default:
        break;
    }
}
