#include "string_buffer.h"

#include <gtest/gtest.h>
#include <memory.h>

TEST(string_buffer, simple)
{
    char *buffer = (char *)malloc(1024);
    memset(buffer, 0, 1024);
    add_string(buffer, "test");
    add_string(buffer, "123");
    add_string(buffer, "me");
    print_strings(buffer);
    free(buffer);
}