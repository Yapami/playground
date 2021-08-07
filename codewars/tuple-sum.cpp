#include <gtest/gtest.h>

#include <string>
#include <tuple>

template<class T>
double add(T v)
{
    return 0.0;
}

template<>
double add(double v)
{
    return v;
}

template<>
double add(int v)
{
    return v;
}

template<typename Tuple, typename F, std::size_t... Indices>
void for_each_impl(Tuple &&tuple, F &&f, std::index_sequence<Indices...>)
{
    using swallow = int[];
    (void)swallow{1, (f(std::get<Indices>(std::forward<Tuple>(tuple))), void(), int{})...};
}

template<typename Tuple, typename F>
void for_each(Tuple &&tuple, F &&f)
{
    constexpr std::size_t N = std::tuple_size<std::remove_reference_t<Tuple>>::value;
    for_each_impl(std::forward<Tuple>(tuple), std::forward<F>(f), std::make_index_sequence<N>{});
}

template<typename... Ts>
double tuple_sum(const std::tuple<Ts...> &tpl)
{
    double sum = 0.0;
    for_each(tpl, [&sum](auto x) { sum += add(x); });
    return sum;
}

TEST(TupleSum, sample)
{
    EXPECT_NEAR(tuple_sum(std::make_tuple(3.14, 42, 'a', "Hello", "World")), 45.14, 0.001);
}
