#ifndef POPULATE
#define POPULATE

#include <vector>
#include <string>
#include <unordered_map>
#include "hero.h"


void pop(
    std::vector<std::vector<hero>> & stats,
    const std::vector<std::vector<std::vector<std::string>>> & codes,
    const std::unordered_map<std::string, head> & h_catalog,
    const std::unordered_map<std::string, arm> & l_catalog,
    const std::unordered_map<std::string, arm> & r_catalog,
    const std::unordered_map<std::string, bottom> & b_catalog
);

void printStats(
    std::vector<std::vector<hero>> & stats
);



#endif