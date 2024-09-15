#include "hero.h"


hero::hero(
    std::string h_code,
    std::string l_code,
    std::string r_code,
    std::string b_code,
    const std::unordered_map<std::string, head> & h_catalog,
    const std::unordered_map<std::string, arm> & l_catalog,
    const std::unordered_map<std::string, arm> & r_catalog,
    const std::unordered_map<std::string, bottom> & b_catalog,
    std::string nick
) : h(h_catalog.at(h_code)), l(l_catalog.at(l_code)), r(r_catalog.at(r_code)), b(b_catalog.at(b_code))
{
}

head hero::get_h() {return h;}
arm hero::get_l() {return l;}
arm hero::get_r()  {return r;}
bottom hero::get_b() {return b;}
std::string hero::get_nickname() {return nickname;}

