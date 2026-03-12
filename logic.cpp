#include <stdio.h>
#include "logic.h"
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/* Функция устанавливает ошибку в контексте.
   Устанавливает флаг ошибки */
static void setError(AppContext* ctx, const char* msg)
{
    ctx->hasError = 1;

    // Если старое сообщение уже было — удаляем его
    if (ctx->errorMessage)
        free(ctx->errorMessage);

    // Выделение памяти под новую ошибку (+1 из-за \0 в конце строки)
    ctx->errorMessage = (char*)malloc(strlen(msg) + 1);

    // Текст ошибки хранится в errorMessage
    strcpy(ctx->errorMessage, msg);
}

// Функция очищает состояние ошибки в контексте
static void clearError(AppContext* ctx)
{
    ctx->hasError = 0;

    if (ctx->errorMessage)
    {
        free(ctx->errorMessage);
        ctx->errorMessage = NULL;
    }
}

// Функция для проверки введенной строки до перевода
void validateInput(AppContext* ctx)
{
    clearError(ctx);

    // Строки нет || строка есть, но в ней 0 символов
    if (!ctx->inputValue || strlen(ctx->inputValue) == 0)
    {
        setError(ctx, "Пустой ввод");
        return;
    }

    // Чтобы не писать ctx->inputValue, а писать s
    char* s = ctx->inputValue;

    // Проверка десятичной СС
    if (ctx->sourceBase == 10)
    {
        int i = 0;

        /* Если первый символ '-', то число отрицательное,
           и начинаем проверку не с первого символа, а со второго */
        if (s[0] == '-')
            i = 1;

        for (; s[i]; i++)
        {
            if (s[i] < '0' || s[i] > '9')
            {
                setError(ctx, "Недопустимый символ для десятичной системы");
                return;
            }
        }
    }

    // Проверка двоичной СС
    if (ctx->sourceBase == 2)
    {
        for (int i = 0; s[i]; i++)
        {
            if (s[i] != '0' && s[i] != '1')
            {
                setError(ctx, "Допустимы только 0 и 1");
                return;
            }
        }

        if (strlen(s) > 32)
        {
            setError(ctx, "Слишком длинное двоичное число");
            return;
        }
    }

    // Проверка восьмеричной СС
    if (ctx->sourceBase == 8)
    {
        for (int i = 0; s[i]; i++)
        {
            if (s[i] < '0' || s[i] > '7')
            {
                setError(ctx, "Допустимы цифры 0..7");
                return;
            }
        }

        if (strlen(s) > 11)
        {
            setError(ctx, "Слишком длинное восьмеричное число");
            return;
        }
    }
}

// Функция преобразует введённую строку в число int
void parseInput(AppContext* ctx)
{
    if (ctx->hasError)
        return;

    // Для десятичной системы используем strtol (string to long)
    if (ctx->sourceBase == 10)
    {
        long val = strtol(ctx->inputValue, NULL, 10);

        if (val < INT_MIN || val > INT_MAX)
        {
            setError(ctx, "Число выходит за диапазон");
            return;
        }
    // Если все норм, то число сохраняем в контекст
        ctx->parsedValue = (int)val;
    }

    // Для двоичной системы переводим строку в число вручную
    if (ctx->sourceBase == 2)
    {
        unsigned int value = 0;
        char* s = ctx->inputValue;
    // Алгоритм перевода строки в число.
        for (int i = 0; s[i]; i++)
        {
            value = value * 2 + (s[i] - '0');
        }

        ctx->parsedValue = (int)value;
    }

    // Для восьмеричной системы переводим строку в число вручную
    if (ctx->sourceBase == 8)
    {
        unsigned int value = 0;
        char* s = ctx->inputValue;

        for (int i = 0; s[i]; i++)
        {
            value = value * 8 + (s[i] - '0');
        }

        ctx->parsedValue = (int)value;
    }
}

// Функция переводит число в нужную систему счисления
void convertValue(AppContext* ctx)
{
    if (ctx->hasError)
        return;

    // Если старый результат уже был — удаляем его
    if (ctx->outputValue)
    {
        free(ctx->outputValue);
        ctx->outputValue = NULL;
    }
    // Value - число, которое нужно перевести
    int value = ctx->parsedValue;

    // Перевод в десятичную систему
    if (ctx->targetBase == 10)
    {
        ctx->outputValue = (char*)malloc(50);
        // Функция - запись value в строку как десятичное число
        sprintf(ctx->outputValue, "%d", value);
        return;
    }

    // Перевод в двоичную систему
    if (ctx->targetBase == 2)
    {
        // 33 так как есть \0 в конце
        ctx->outputValue = (char*)malloc(33);

        // Используем unsigned int, чтобы получить битовое представление числа
        unsigned int v = (unsigned int)value;

        // Проходим по всем 32 битам числа
        for (int i = 31; i >= 0; i--)
        {
            ctx->outputValue[31 - i] = ((v >> i) & 1) + '0'; // ((v >> i) & 1) - берем i-й бит числа
        }

        ctx->outputValue[32] = '\0';
        return;
    }

    // Перевод в восьмеричную систему
    if (ctx->targetBase == 8)
    {
        ctx->outputValue = (char*)malloc(12);

        // Используем unsigned int для корректного представления в дополнительном коде
        unsigned int v = (unsigned int)value;

        sprintf(ctx->outputValue, "%011o", v);
        return;
    }
}
