#define  DONE    1
#if      !DONE

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "../Stack/stack.h"

/* Section : Functions Declaration */
int checkParenthesis(char *str, int size);
int isClosing(char s);
int isOpening(char s);

int main(void)
{
    char str[] = "({[]})";

    if (checkParenthesis(str, 6))
        printf("Every Symbol Matched!\n");
    else
        printf("Some Symbols Were Never Matched!\n");
}

/* Section : Functions Definitions */
int isOpening(char s)
{
    if (s == '(' || s == '{' || s == '[')
        return true;
    else
        return false;
}

int isClosing(char s)
{
    if (s == ')' || s == '}' || s == ']')
        return true;
    else
        return false;
}

int doesMatch(char a, char b)
{
    if (('(' == a) && (')' == b))
        return true;
    else if (('{' == a) && ('}' == b))
        return true;
    else if (('[' == a) && (']' == b))
        return true;
    else
        return false;

}

int checkParenthesis(char *str, int size)
{
    Stack stack;
    stack_init(&stack, sizeof(char), size);

    for(int i = 0; i < size; ++i)
    {
        if(isOpening(str[i]))
        {
            stack_push(&stack, &str[i]);
        }
        else if (isClosing(str[i]))
        {
            if(stack_isEmpty(&stack))
                return false;
            else
            {
                char x;
                stack_pop(&stack, &x);
                if(!doesMatch(x, str[i]))
                    return false;
            }
        }
    }

    return (stack_isEmpty(&stack))
}
#endif

