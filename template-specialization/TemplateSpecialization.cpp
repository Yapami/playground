#include <gmock/gmock.h>
#include <gtest/gtest.h>

class TemplateSpecialization : public testing::Test
{
public:
    enum class Digits
    {
        ONE,
        TWO,
        THREE,
    };

    template<Digits>
    uint32_t digit()
    {
        throw std::runtime_error("Wrong enum value");
        return 0;
    }
};

template<>
uint32_t TemplateSpecialization::digit<TemplateSpecialization::Digits::ONE>()
{
    return 1;
}

template<>
uint32_t TemplateSpecialization::digit<TemplateSpecialization::Digits::TWO>()
{
    return 2;
}

template<>
uint32_t TemplateSpecialization::digit<TemplateSpecialization::Digits::THREE>()
{
    return 3;
}

TEST_F(TemplateSpecialization, test)
{
    EXPECT_EQ(digit<Digits::ONE>(), 1);
    EXPECT_EQ(digit<Digits::TWO>(), 2);
    EXPECT_EQ(digit<Digits::THREE>(), 3);
    EXPECT_THROW(digit<static_cast<Digits>(5)>(), std::runtime_error);
}