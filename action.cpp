#include "action.h"

void effect(std::pair<int,int> atker, char atking_part, std::pair<int,int> target, std::vector<std::vector<hero>> & stats) {

    std::string code = "";

    if(atking_part == 'h') {
        code = stats[atker.first][atker.second].get_h().get_code();
        code[0] = '1';
    }
    else if(atking_part == 'l') {
        code = stats[atker.first][atker.second].get_l().get_code();
        code[0] = '2';
    }
    else if(atking_part == 'r') {
        code = stats[atker.first][atker.second].get_r().get_code();
        code[0] = '3';
    }
    else {
        code = stats[atker.first][atker.second].get_b().get_code();
        code[0] = '4';
    }

    switch (stoi(code))
    {
    case 10000001:
        std::cout << "10000001" << std::endl;

    

        break;
    
    default:
        break;
    }



}

/*
// attacking function can use HUGE rework
void attack(
    std::vector<std::vector<hero>> & stats,
    const std::vector<std::vector<std::pair<double, bool>>> & pos, 
    std::pair<int,int> atker,
    char atking_part, 
    bool chain,
    bool closest,
    bool furthest,
    std::pair<int,int> target, // if second is -1, random target
    char target_part // if == z, random
) {

    // pow system may need refinement
    // int damage = 2 * a * 0.5 ^ (2 * DEF / ATK)

    int ATK = 0; int CRIT = 0; int ACU = 0;
    if (atking_part == 'h') {
        ATK = stats[atker.first][atker.second].get_h().get_power();
        CRIT = stats[atker.first][atker.second].get_h().get_crit();
        ACU = stats[atker.first][atker.second].get_h().get_accuracy();
    }
    else if (atking_part == 'l') {
        ATK = stats[atker.first][atker.second].get_l().get_power();
        CRIT = stats[atker.first][atker.second].get_l().get_crit();
        ACU = stats[atker.first][atker.second].get_l().get_accuracy();
    }
    else if (atking_part == 'r') {
        ATK = stats[atker.first][atker.second].get_r().get_power();
        CRIT = stats[atker.first][atker.second].get_r().get_crit();
        ACU = stats[atker.first][atker.second].get_r().get_accuracy();
    }
    else if (atking_part == 'b') {
        ATK = stats[atker.first][atker.second].get_b().get_power();
        CRIT = stats[atker.first][atker.second].get_b().get_crit();
        ACU = stats[atker.first][atker.second].get_b().get_accuracy();
    }

    // crit system may need refinement
    int crit_roll = getRandom32Bit()%100;
    if( (crit_roll) < CRIT*100) {
        std::cout << "crit roll: " << crit_roll << std::endl; 
        ATK=ATK*2;
    }

    // choose target
    if(closest) {
        target.second = get_closest_to_action(pos, stats, target.first);
    }
    else if (furthest) {
        target.second = get_furthest_to_action(pos, stats, target.first);
    }
    else if (target.second == -1) {
        while(target.second == -1) {
            int random_unit = getRandom32Bit()%stats[target.first].size();
            if(stats[target.first][target.second].get_h().get_hp() > 0) {
                target.second = random_unit;
            }
        }
    }
    //else if target is dead
 
    // how does dodge/accuracy work? right now just use success_rate = 2a *0.5^(2d/a)
    int dodge_roll = getRandom32Bit()%100;
    int DOG = stats[target.first][target.second].bb_dodge;
    if( (dodge_roll) < (2*ACU*pow(0.5,2*(double)DOG/(double)ACU)) ) { // attack was successful

        // how does part deference work? 
        // (1) based on sum(DEF)/400, based on level, determines deferrance to parts
        // (2) could be based on individual DEF, likelihood to defer
        // (3) share of total DEF is the rate it goes there **


        while( (ATK > 0) && (stats[target.first][target.second].bh_hp > 0) ) {
            double sum_DEF = 0;

            sum_DEF += (stats[target.first][target.second].bh_hp > 0) ? stats[target.first][target.second].bh_power : 0;
            sum_DEF += (stats[target.first][target.second].bl_hp > 0) ? stats[target.first][target.second].bl_power : 0;
            sum_DEF += (stats[target.first][target.second].br_hp > 0) ? stats[target.first][target.second].br_power : 0;
            sum_DEF += (stats[target.first][target.second].bb_hp > 0) ? stats[target.first][target.second].bb_power : 0;

            // DEAL WITH POW/DEF FORMULA LATER
            int part_roll = getRandom32Bit()%100;
            if(part_roll<(100*(double)(stats[target.first][target.second].bh_def)/sum_DEF)) {
                std::cout << atker.first << " " << atker.second << " " << target.first << " " << target.second << " h " << ATK << " " << stats[target.first][target.second].bh_hp << std::endl;
                stats[target.first][target.second].bh_hp -= ATK;
                ATK = 0;
            }
            else if(part_roll<(100*(double)(stats[target.first][target.second].bh_power+stats[target.first][target.second].bl_def)/sum_DEF)) {
                std::cout << atker.first << " " << atker.second << " " << target.first << " " << target.second << " l " << ATK << " " << stats[target.first][target.second].bl_hp << std::endl;
                stats[target.first][target.second].bl_hp -= ATK;
                if( (stats[target.first][target.second].bl_hp < 0) && (chain)) ATK = -stats[target.first][target.second].bl_hp;
                else ATK = 0;
            }
            else if(part_roll<(100*(double)(stats[target.first][target.second].bh_def+stats[target.first][target.second].bl_def+stats[target.first][target.second].br_def)/sum_DEF)) {
                std::cout << atker.first << " " << atker.second << " " << target.first << " " << target.second << " r " << ATK << " " << stats[target.first][target.second].br_hp << std::endl;
                stats[target.first][target.second].br_hp -= ATK;
                if( (stats[target.first][target.second].br_hp < 0) && (chain)) ATK = -stats[target.first][target.second].br_hp;
                else ATK = 0;
            }
            else {
                std::cout << atker.first << " " << atker.second << " " << target.first << " " << target.second << " b " << ATK << " " << stats[target.first][target.second].bb_hp << std::endl;
                stats[target.first][target.second].bb_hp -= ATK;
                if( (stats[target.first][target.second].bb_hp < 0) && (chain)) ATK = -stats[target.first][target.second].bb_hp;
                else ATK = 0;
            }
        }
    }
    else {
        std::cout << "missed" << std::endl;
    }





}

*/
void attack_AOE() {}
void buff() {}
void buff_AOE() {}
void debuff() {}
void debuff_AOE() {}
void heal() {}
void heal_AOE() {}