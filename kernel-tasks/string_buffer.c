#include "string_buffer.h"

#include <stdio.h>
#include <string.h>

void add_string(char *buffer, const char *str)
{
    char *p = buffer;
    while (*p)
    {
        p += strlen(p);
        ++p;
    }
    strcpy(p, str);
}

void print_strings(char *buffer)
{
    char *p = buffer;
    while (*p)
    {
        printf("%s\n", p);
        p += strlen(p);
        ++p;
    }
}