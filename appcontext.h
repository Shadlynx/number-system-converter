#ifndef APPCONTEXT_H
#define APPCONTEXT_H

struct AppContext
{
    int sourceBase;
    int targetBase;

    char* inputValue;
    char* outputValue;

    int parsedValue;

    int hasError;
    char* errorMessage;
};

#endif
