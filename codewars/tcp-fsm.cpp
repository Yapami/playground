#include <gtest/gtest.h>

#include <string>
#include <unordered_map>
#include <vector>

using Transition = std::pair<std::string, std::string>;
using Transitions = std::vector<Transition>;

std::unordered_map<std::string, Transitions> TRANSITIONS = {
    {
        "CLOSED",
        {{"APP_PASSIVE_OPEN", "LISTEN"}, {"APP_ACTIVE_OPEN", "SYN_SENT"}},
    },
    {
        "LISTEN",
        {{"RCV_SYN", "SYN_RCVD"}, {"APP_SEND", "SYN_SENT"}, {"APP_CLOSE", "CLOSED"}},
    },
    {
        "SYN_RCVD",
        {{"APP_CLOSE", "FIN_WAIT_1"}, {"RCV_ACK", "ESTABLISHED"}},
    },
    {
        "SYN_SENT",
        {{"RCV_SYN", "SYN_RCVD"}, {"RCV_SYN_ACK", "ESTABLISHED"}, {"APP_CLOSE", "CLOSED"}},
    },
    {
        "ESTABLISHED",
        {{"APP_CLOSE", "FIN_WAIT_1"}, {"RCV_FIN", "CLOSE_WAIT"}},
    },
    {
        "FIN_WAIT_1",
        {{"RCV_FIN", "CLOSING"}, {"RCV_FIN_ACK", "TIME_WAIT"}, {"RCV_ACK", "FIN_WAIT_2"}},
    },
    {
        "CLOSING",
        {{"RCV_ACK", "TIME_WAIT"}},
    },
    {
        "FIN_WAIT_2",
        {{"RCV_FIN", "TIME_WAIT"}},
    },
    {
        "TIME_WAIT",
        {{"APP_TIMEOUT", "CLOSED"}},
    },
    {
        "CLOSE_WAIT",
        {{"APP_CLOSE", "LAST_ACK"}},
    },
    {
        "LAST_ACK",
        {{"RCV_ACK", "CLOSED"}},
    },
};

std::string traverse_TCP_states(const std::vector<std::string> &events)
{
    std::string s = "CLOSED";
    for (const auto &e : events)
    {
        auto m = TRANSITIONS.find(s);
        if (m == TRANSITIONS.end())
        {
            return "ERROR";
        }
        auto t = std::find_if(m->second.begin(), m->second.end(),
                              [e](const Transition &t) { return t.first == e; });
        if (t == m->second.end())
        {
            return "ERROR";
        }
        s = t->second;
    }
    return s;
}

TEST(CodeWars, tcp_fsm)
{
    using vs = std::vector<std::string>;

    vs test1 = {"APP_ACTIVE_OPEN", "RCV_SYN_ACK", "RCV_FIN"};
    vs test2 = {"APP_PASSIVE_OPEN", "RCV_SYN", "RCV_ACK"};
    vs test3 = {"APP_ACTIVE_OPEN", "RCV_SYN_ACK", "RCV_FIN", "APP_CLOSE"};
    vs test4 = {"APP_ACTIVE_OPEN"};
    vs test5 = {"APP_PASSIVE_OPEN", "RCV_SYN", "RCV_ACK", "APP_CLOSE", "APP_SEND"};

    EXPECT_EQ(traverse_TCP_states(test1), "CLOSE_WAIT");
    EXPECT_EQ(traverse_TCP_states(test2), "ESTABLISHED");
    EXPECT_EQ(traverse_TCP_states(test3), "LAST_ACK");
    EXPECT_EQ(traverse_TCP_states(test4), "SYN_SENT");
    EXPECT_EQ(traverse_TCP_states(test5), "ERROR");
}