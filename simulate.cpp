#include "simulate.h"

#include <vector>
#include <iostream>
#include "limits.h"
#include "float.h"

#include "utility.h"




int simulate(
    std::vector<std::vector<std::vector<int>>> & pos, 
    std::vector<std::vector<hero>> & stats
) {

    double min_multiple = DBL_MAX;
    int min_units = INT_MAX;

    // calculate who has the closest action
    for(int i = 0; i < pos.size(); i++) {
        for(int j = 0; j < pos[i].size(); j++) {

            double left = (pos[i][j][1]) ? (100 - pos[i][j][0]) : pos[i][j][0] ;
            double multiple = left / (double)stats[i][j].get_b().get_speed();
            min_multiple = (min_multiple > multiple) ? multiple : min_multiple;

            std::cout << i << " " << j << " " << left << " " << multiple << " " << stats[i][j].get_b().get_speed() << " " << min_multiple << std::endl;
        }
    }

    // calculate next positions for everyone else
    for(int i = 0; i < pos.size(); i++) {
        for(int j = 0; j < pos[i].size(); j++) {

            std::cout << i <<" " << j << ": " << pos[i][j][0] << " " << pos[i][j][1] << "; ";
            pos[i][j][0] = (pos[i][j][1]) ? pos[i][j][0] + round5(min_multiple * (double)stats[i][j].get_b().get_speed() ) : pos[i][j][0] - round5(min_multiple * (double)stats[i][j].get_b().get_speed() );
            if( (pos[i][j][0] >= 100) && (pos[i][j][1]) ) {
                pos[i][j][0] = 100;
                pos[i][j][1] = false;
            }
            else if( (pos[i][j][0] <= 0) && (!pos[i][j][1]) ) {
                pos[i][j][0] = 0;
                pos[i][j][1] = true;
            }
            std::cout << pos[i][j][0] << " " << pos[i][j][1] << std::endl;

        }
    }

    return min_units;
}

int get_closest_to_action(
    std::vector<std::vector<std::vector<int>>> & pos,
    std::vector<std::vector<hero>> & stats,
    int team
) {
    
    int closest = 0;
    double min_multiple = DBL_MAX;

    for(int i = 0; i < pos[team].size(); i++) {
            double left = (pos[team][i][1]) ? (100 - pos[team][i][0]) : pos[team][i][0] ;
            double multiple = left / (double)stats[team][i].get_b().get_speed() ;
            min_multiple = (min_multiple > multiple) ? multiple : min_multiple;
            closest = (min_multiple > multiple) ? i : closest;

            std::cout << team << " " << i << " " << left << " " << multiple << " " << stats[team][i].get_b().get_speed() << " " << min_multiple << std::endl;
    }

    return closest;
}

int get_furthest_to_action(
    std::vector<std::vector<std::vector<int>>> & pos,
    std::vector<std::vector<hero>> & stats,
    int team
) {

    int furthest = 0;
    double max_multiple = 0;

    for(int i = 0; i < pos[team].size(); i++) {
            double left = (pos[team][i][1]) ? (100 - pos[team][i][0]) : pos[team][i][0] ;
            double multiple = left / (double)stats[team][i].get_b().get_speed() ;
            max_multiple = (max_multiple < multiple) ? multiple : max_multiple;
            furthest = (max_multiple < multiple) ? multiple : max_multiple;

            std::cout << team << " " << i << " " << left << " " << multiple << " " << stats[team][i].get_b().get_speed() << " " << max_multiple << std::endl;
    }

    return furthest;
}

