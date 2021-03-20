#include "App.h"

#include <gtest/gtest.h>

TEST(TestApp, correct)
{
    App app;
    EXPECT_EQ(app.add(2, 2), 2 + 2);
}

TEST(TestApp, failed_triangulation)
{
    App app;
    EXPECT_EQ(app.add(1, 2), 1 + 2);
}
