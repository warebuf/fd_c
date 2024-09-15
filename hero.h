#ifndef HERO
#define HERO

#include <string>
#include "part.h"


class hero {
public:
    hero(
    std::string h_code,
    std::string l_code,
    std::string r_code,
    std::string b_code,
    const std::unordered_map<std::string, head> & h_catalog,
    const std::unordered_map<std::string, arm> & l_catalog,
    const std::unordered_map<std::string, arm> & r_catalog,
    const std::unordered_map<std::string, bottom> & b_catalog,
    std::string nick
    );

    head get_h(); // potentially change these to return by reference, but apparently compiler optimizes for this... but still...
    arm get_l();
    arm get_r();
    bottom get_b();
    std::string get_nickname();

private:
    head h;
    arm l;
    arm r;
    bottom b;
    std::string nickname;
};


#endif
