#ifndef SIMULATE
#define SIMULATE

#include <vector>
#include <unordered_map>
#include "hero.h"


int simulate(
    std::vector<std::vector<std::vector<int>>> & pos, 
    std::vector<std::vector<hero>> & stats
);

int get_closest_to_action(
    std::vector<std::vector<std::vector<int>>> & pos,
    std::vector<std::vector<hero>> & stats,
    int team
);

int get_furthest_to_action(
    std::vector<std::vector<std::vector<int>>> & pos,
    std::vector<std::vector<hero>> & stats,
    int team
);



#endif