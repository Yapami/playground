#include "JosephusProblem.h"

struct List
{
    uint32_t index = 1;
    List *next = nullptr;
};

uint32_t list_solution(uint32_t n, uint32_t k)
{
    List *head = new List;
    List *c = head;
    for (uint32_t i = 2; i <= n; ++i)
    {
        c->next = new List{i, nullptr};
        c = c->next;
    }
    c->next = head;
    auto p = c;
    c = head;
    uint32_t steps = k;
    while (true)
    {
        for (uint32_t i = 1; i < steps; ++i)
        {
            c = c->next;
            p = p->next;
        }
        if (p->next != p)
        {
            p->next = c->next;
            delete c;
            c = p->next;
        }
        else
        {
            return c->index;
        }
    }
    return 0;
}

uint32_t iterative_solution(uint32_t n, uint32_t k)
{
    uint32_t p = 0;
    for (uint32_t r = 2; r <= n; ++r)
    {
        p = (p + k) % r;
    }
    return p + 1;
}