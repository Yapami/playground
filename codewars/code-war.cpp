#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <map>
#include <set>
#include <string>

namespace preloaded
{
const std::string words[] = {
    "ACT",  "ADD",  "ALL",  "APE",  "AND",  "ANN",  "ANY",  "ANT",  "ARE",  "ART",  "ASS",  "BAD",
    "BAR",  "BAT",  "BAY",  "BEE",  "BIG",  "BIT",  "BOB",  "BOY",  "BUN",  "BUT",  "CAN",  "CAR",
    "CAT",  "COT",  "COW",  "CUT",  "DAD",  "DAY",  "DEW",  "DID",  "DIN",  "DOG",  "DON",  "DOT",
    "DUD",  "EAR",  "EAT",  "EEL",  "EGG",  "ERR",  "EYE",  "FAG",  "FAR",  "FLY",  "FOR",  "FUN",
    "FUR",  "GAY",  "GET",  "GOT",  "GUM",  "GUN",  "GUY",  "GUT",  "GYM",  "HAS",  "HAT",  "HER",
    "HEY",  "HIM",  "HIS",  "HIT",  "HOW",  "HUG",  "HUN",  "ICE",  "INK",  "ITS",  "IVE",  "JAN",
    "JET",  "JOB",  "JOT",  "JOY",  "KEY",  "LAP",  "LAY",  "LIE",  "LET",  "LOG",  "MAN",  "MAP",
    "MAY",  "MEN",  "MOM",  "MUD",  "MUM",  "NAP",  "NEW",  "NOD",  "NOT",  "NOW",  "OAR",  "ODD",
    "OFF",  "OLD",  "ONE",  "OUR",  "OUT",  "PAN",  "PAL",  "PAT",  "PAW",  "PEN",  "PET",  "PIG",
    "PIT",  "POT",  "PRO",  "PUT",  "QUO",  "RAG",  "RAM",  "RAN",  "RAP",  "RAT",  "RED",  "RIP",
    "ROD",  "ROT",  "RUN",  "RUT",  "SAT",  "SAW",  "SAY",  "SEA",  "SEE",  "SEX",  "SHE",  "SOY",
    "SUN",  "SUX",  "TAN",  "TAT",  "TEA",  "THE",  "TIN",  "TIP",  "TIT",  "TON",  "TOP",  "TOO",
    "TWO",  "URN",  "USE",  "VAN",  "VET",  "VIP",  "WAR",  "WAS",  "WAY",  "WED",  "WHO",  "WHY",
    "WIN",  "WON",  "XXX",  "YAK",  "YAM",  "YAP",  "YOU",  "YUM",  "ZAP",  "ZIP",  "ZIT",  "ZOO",
    "ABLE", "ACED", "AGOG", "AHEM", "AHOY", "ALLY", "AMEN", "ANTI", "ANTS", "ANUS", "APES", "ARMY",
    "ARSE", "ARTY", "AVID", "AWED", "BABY", "BARS", "BATS", "BAYS", "BEAR", "BEES", "BILL", "BITE",
    "BITS", "BLOW", "BLUE", "BOLD", "BONE", "BOOB", "BOOM", "BOSS", "BOYS", "BUFF", "BUNG", "BUNS",
    "BUMS", "BURP", "BUST", "BUSY", "BUZZ", "CANS", "CANT", "CARS", "CART", "CATS", "CHAP", "CHIC",
    "CHUM", "CIAO", "CLAP", "COCK", "CODE", "COOL", "COWS", "COZY", "CRAB", "CREW", "CURE", "CULT",
    "DADS", "DAFT", "DAWN", "DAYS", "DECK", "DEED", "DICK", "DING", "DOGS", "DOTS", "DOLL", "DOLT",
    "DONG", "DOPE", "DOWN", "DRAW", "DUCK", "DUDE", "DUMB", "DUTY", "EARL", "EARN", "EARS", "EASY",
    "EATS", "EDGE", "EELS", "EGGS", "ENVY", "EPIC", "EYES", "FACE", "FAGS", "FANG", "FARM", "FART",
    "FANS", "FAST", "FEAT", "FEET", "FISH", "FIVE", "FIZZ", "FLAG", "FLEW", "FLIP", "FLOW", "FOOD",
    "FORT", "FUCK", "FUND", "GAIN", "GEEK", "GEMS", "GIFT", "GIRL", "GIST", "GIVE", "GLEE", "GLOW",
    "GOLD", "GOOD", "GOSH", "GRAB", "GRIN", "GRIT", "GROT", "GROW", "GRUB", "GUNS", "GUSH", "GYMS",
    "HAIL", "HAIR", "HALO", "HANG", "HATS", "HEAD", "HEAL", "HEIR", "HELL", "HELP", "HERE", "HERO",
    "HERS", "HIGH", "HIRE", "HITS", "HOLY", "HOPE", "HOST", "HUNK", "HUGE", "HUNG", "HUNS", "HURT",
    "ICON", "IDEA", "IDLE", "IDOL", "IOTA", "JAZZ", "JERK", "JESS", "JETS", "JINX", "JOBS", "JOHN",
    "JOKE", "JUMP", "JUNE", "JULY", "JUNK", "JUST", "KATA", "KEYS", "KICK", "KIND", "KING", "KISS",
    "KONG", "KNOB", "KNOW", "LARK", "LATE", "LEAN", "LICE", "LICK", "LIKE", "LION", "LIVE", "LOGS",
    "LOCK", "LONG", "LOOK", "LORD", "LOVE", "LUCK", "LUSH", "MAKE", "MANY", "MART", "MATE", "MAXI",
    "MEEK", "MIKE", "MILD", "MINT", "MMMM", "MOMS", "MOOD", "MOON", "MOOT", "MUCH", "MUFF", "MUMS",
    "MUTT", "NAPS", "NAZI", "NEAT", "NECK", "NEED", "NEWS", "NEXT", "NICE", "NICK", "NOON", "NOSE",
    "NOTE", "OARS", "OATS", "ONCE", "ONLY", "OPEN", "ORGY", "OVAL", "OVER", "PANS", "PALS", "PART",
    "PAST", "PATS", "PAWS", "PEAR", "PERT", "PENS", "PETS", "PHEW", "PIPE", "PIPS", "PLAN", "PLUM",
    "PLUS", "POET", "POOF", "POOP", "POSH", "POTS", "PROS", "PSST", "PUKE", "PUNK", "PURE", "PUSH",
    "PUSS", "QUAD", "QUAK", "QUID", "QUIT", "RANT", "RAPE", "RAPS", "RAPT", "RATE", "RAMS", "RATS",
    "REAP", "RICK", "RING", "RIPE", "ROOT", "ROSE", "ROSY", "ROTS", "RUNT", "RUTS", "SAFE", "SAGE",
    "SANE", "SAVE", "SAWS", "SEEK", "SEXY", "SHAG", "SHIT", "SICK", "SIGH", "SIRE", "SLAG", "SLIT",
    "SLUT", "SNAP", "SNOG", "SNUG", "SOFT", "SOON", "SOUL", "SOUP", "SPRY", "STIR", "STUN", "SUCK",
    "SWAG", "SWAY", "TACT", "TANK", "TANS", "THAT", "THIS", "TIME", "TINS", "TINY", "TITS", "TOES",
    "TONS", "TONY", "TOPS", "TOYS", "UBER", "URNS", "USED", "USER", "USES", "VAIN", "VAMP", "VARY",
    "VEIN", "VENT", "VERY", "VEST", "VIEW", "VIVA", "VOLT", "VOTE", "WAFT", "WAGE", "WAKE", "WALK",
    "WALL", "WANG", "WANK", "WANT", "WARD", "WARM", "WARP", "WARS", "WART", "WASH", "WAVE", "WEAR",
    "WEDS", "WEED", "WEEN", "WELD", "WHAT", "WHEE", "WHEW", "WHIP", "WHIZ", "WHOA", "WIFE", "WILL",
    "WIND", "WING", "WINK", "WINS", "WIRE", "WISH", "WITH", "WORD", "WORK", "WRAP", "XMAN", "XMEN",
    "XRAY", "XTRA", "XXXX", "YANK", "YAKS", "YAMS", "YAPS", "YARD", "YARN", "YELP", "YERN", "YOKE",
    "YOLK", "YULE", "ZANY", "ZAPS", "ZIPS", "ZITS", "ZERO", "ZOOM", "ZOOS"};
}

std::map<char, char> generate_mapping()
{
    std::map<char, char> m;
    char d = 0;
    char o = 0;
    static const char counts[] = {3, 3, 3, 3, 3, 4, 3, 4};
    for (char c = 'A'; c <= 'Z'; ++c, ++d)
    {
        if (counts[static_cast<size_t>(o)] == d)
        {
            ++o;
            d = 0;
        }
        m[c] = o + 2;
    }
    return m;
}

std::map<char, char>::const_iterator get_start_mapping(const std::map<char, char> &m, char c)
{
    auto it = m.find(c);
    char d = it->second;
    while (it != m.begin() && std::prev(it)->second == d)
    {
        --it;
    }
    return it;
}

std::map<char, char>::const_iterator get_end_mapping(const std::map<char, char> &m, char c)
{
    auto it = m.find(c);
    char d = it->second;
    while (it != m.end() && std::next(it)->second == d)
    {
        ++it;
    }
    return it;
}

bool is_acceptable_alternative(const std::map<char, char> &m, const std::string &s,
                               const std::vector<char> &options)
{
    if (options.size() != s.size())
    {
        return false;
    }
    for (size_t i = 0; i < s.size(); ++i)
    {
        if (options[i] != m.at(s.at(i)))
        {
            return false;
        }
    }
    return true;
}

std::set<std::string> get_alternatives(const std::string &str)
{
    std::set<std::string> result;
    std::vector<char> options;

    static std::set<std::string> pre;
    if (pre.empty())
    {
        for (const auto &w : preloaded::words)
        {
            pre.insert(w);
        }
    }
    static auto m = generate_mapping();

    std::string fc(3, 'A');
    std::string lc(4, 'Z');

    fc.front() = get_start_mapping(m, str.front())->first;
    lc.front() = get_end_mapping(m, str.front())->first;
    auto s = pre.lower_bound(fc);
    auto e = pre.upper_bound(lc);

    for (auto c : str)
    {
        options.push_back(m.at(c));
    }
    for (; s != e; ++s)
    {
        if (is_acceptable_alternative(m, *s, options))
        {
            result.insert(*s);
        }
    }
    return result;
}

std::set<std::string> check1800(const std::string &str)
{
    std::set<std::string> result;

    auto sd = str.find_last_of('-');
    auto sw = str.substr(sd + 1);
    auto fd = str.find_last_of('-', sd - 1);
    auto fw = str.substr(fd + 1, sd - fd - 1);

    auto fa = get_alternatives(fw);
    auto sa = get_alternatives(sw);
    for (const auto &w1 : fa)
    {
        for (const auto &w2 : sa)
        {
            std::stringstream ss;
            ss << "1-800-" << w1 << '-' << w2;
            result.insert(ss.str());
        }
    }
    if (fw.length() > sw.length())
    {
        sw.insert(0, 1, fw.back());
        fw.pop_back();
    }
    else
    {
        fw.push_back(sw.front());
        sw.erase(0, 1);
    }
    fa = get_alternatives(fw);
    sa = get_alternatives(sw);
    for (const auto &w1 : fa)
    {
        for (const auto &w2 : sa)
        {
            std::stringstream ss;
            ss << "1-800-" << w1 << '-' << w2;
            result.insert(ss.str());
        }
    }
    return result;
}

TEST(CodeWar, example)
{
    // std::set<std::string> Test1 = {"1-800-CODE-WAR", "1-800-CODE-YAP", "1-800-CODE-WAS",
    //                                "1-800-CODE-ZAP"};
    // EXPECT_THAT(check1800("1-800-CODE-WAR"), testing::ContainerEq(Test1));
    std::set<std::string> Test2 = {"1-800-PAL-PEAR", "1-800-PAL-REAP", "1-800-PALS-EAR",
                                   "1-800-PALS-FAR"};
    EXPECT_THAT(check1800("1-800-PAL-PEAR"), testing::ContainerEq(Test2));
}