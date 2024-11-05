#include "string_reverse.h"

#include <string.h>

void swap_chars(char *a, char *b)
{
    char t = *a;
    *a = *b;
    *b = t;
}

void reverse_interval(char *a, char *b)
{
    size_t l = (b - a) / 2;
    for (size_t i = 0; i <= l; ++i, ++a, --b)
    {
        swap_chars(a, b);
    }
}

void reverse_string(char *str)
{
    size_t len = strlen(str);
    reverse_interval(str, str + len - 1);
    char *se = str + strlen(str);
    char *we = strchr(str, ' ');
    if (!we)
    {
        return;
    }
    for (char *ws = str; we; ws = we)
    {
        we = strchr(ws, ' ');
        reverse_interval(ws, we ? we - 1 : se - 1);
        if (we)
        {
            ++we;
        }
    }
}
