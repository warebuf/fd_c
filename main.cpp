/*
GOAL

Within this project, we want to:
- be able to communicate with a javascript client
- build a websocket server that is able to handle multiple concurrent requests
- able to handle messages
- able to handle arrays of data
- able to act as an official timer (like hearthstone)

Once this is done, we will consider what we have to test
- messages
- arrays of information
- can we somehow test how many users it can hold?
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <unordered_map>

#include "catalog.h"
#include "populate.h"
#include "simulate.h"
#include "utility.h"
#include "rng.h"
#include "hero.h"


void initField(std::vector<std::vector<std::vector<int>>> & pos){
    
    for(int i = 0; i < 2; i++) {
        std::vector<std::vector<int>> temp;
        for(int j = 0; j < 5; j++) {
            std::vector<int> temp2;
            temp2.push_back(0);
            temp2.push_back(1);
            temp2.push_back(1);
            temp.push_back(temp2);
        }
        pos.push_back(temp);
    }

    return;
}

int main() {

    // Seed RNG (ISAAC) with the key
    std::string key = "this is my secret key"; 
    seedIsaac(key, true);

    // the reason I decided not to make these global is because we want to make sure no function is accidentally editing these structures (reduces scope at the expense of extra typing)
    std::unordered_map<std::string, head> h_catalog;
    std::unordered_map<std::string, arm> l_catalog;
    std::unordered_map<std::string, arm> r_catalog;
    std::unordered_map<std::string, bottom> b_catalog;

    populate_catalog(h_catalog,l_catalog,r_catalog,b_catalog);

    std::vector<std::vector<std::vector<int>>> pos; // team of heros, [COORDINATE, DIRECTION, ALIVE]

    std::vector<std::vector<hero>> stats;

    std::vector<std::vector<std::vector<std::string>>> codes = 
    {
        {
            {"H0000001", "L0000001", "R0000001", "B0000001","ayayaya"},
            {"H0000002", "L0000002", "R0000002", "B0000002","humpty dumpty"},
            {"H0000003", "L0000003", "R0000003", "B0000003","gertrude"},
            {"H0000002", "L0000002", "R0000002", "B0000002","ricky bobby"},
            {"H0000001", "L0000001", "R0000001", "B0000001","walter white"}
        }
        ,
        {
            {"H0000001", "L0000001", "R0000001", "B0000001","ronaldo"},
            {"H0000002", "L0000002", "R0000002", "B0000002","harry"},
            {"H0000003", "L0000003", "R0000003", "B0000003","gon"},
            {"H0000002", "L0000002", "R0000002", "B0000002","naruto"},
            {"H0000001", "L0000001", "R0000001", "B0000001","yugi"}
        }
    };

    initField(pos);
    pop(stats, codes, h_catalog, l_catalog, r_catalog, b_catalog);
    printStats(stats);

    simulate(pos, stats);
    simulate(pos, stats);
    simulate(pos, stats);

    return 0;
}

