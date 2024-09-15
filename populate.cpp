#include "populate.h"

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>



void pop(
    std::vector<std::vector<hero>> & stats,
    const std::vector<std::vector<std::vector<std::string>>> & codes, 
    const std::unordered_map<std::string, head> & h_c,
    const std::unordered_map<std::string, arm> & l_c,
    const std::unordered_map<std::string, arm> & r_c,
    const std::unordered_map<std::string, bottom> & b_c
) {

    std::cout << "init population" << std::endl;

    for(int i = 0; i < 2; i++) {
        
        std::vector<hero> temp;
        stats.push_back(temp);

        for(int j = 0; j < 5; j++) {
            stats[i].push_back(hero(codes[i][j][0],codes[i][j][1],codes[i][j][2],codes[i][j][3],h_c, l_c, r_c, b_c,codes[i][j][4]));
        }
    }



}

// add a printing function that makes the stats line up after the part_name
void printStats(
    std::vector<std::vector<hero>> & stats
) {
    for(int i = 0; i < stats.size(); i++) {
        for(int j = 0; j < stats[i].size(); j++) {
            int temp = 0;
            std::cout << "HERO " << (i*5) + 1 + j << ": " << stats[i][j].get_nickname() << std::endl;

            std::cout << "   " << stats[i][j].get_h().get_code()  << " " << stats[i][j].get_h().get_part_name();
            temp = 60 - stats[i][j].get_h().get_part_name().length();
            for(int i=0;i<temp;i++) std::cout << " ";
            std::cout << stats[i][j].get_h().get_hp() << std::endl;
            
            std::cout << "   " << stats[i][j].get_l().get_code()  << " " << stats[i][j].get_l().get_part_name();
            temp = 60 - stats[i][j].get_l().get_part_name().length();
            for(int i=0;i<temp;i++) std::cout << " ";
            std::cout << stats[i][j].get_l().get_hp() << std::endl;
            
            std::cout << "   " << stats[i][j].get_r().get_code()  << " " << stats[i][j].get_r().get_part_name(); 
            temp = 60 - stats[i][j].get_r().get_part_name().length();
            for(int i=0;i<temp;i++) std::cout << " ";
            std::cout << stats[i][j].get_r().get_hp() << std::endl;

            std::cout << "   " << stats[i][j].get_b().get_code()  << " "  << stats[i][j].get_b().get_part_name();
            temp = 60 - stats[i][j].get_b().get_part_name().length();
            for(int i=0;i<temp;i++) std::cout << " ";
            std::cout << stats[i][j].get_b().get_hp() << std::endl;
        
        
        }
    }
    std::cout << "EOF" << std::endl;

}
