#include "part.h"

part::part(std::vector<std::string> input) {
    part_class = input[0][0];
    code = input[0];
    part_name = input[1];
    hp = std::stoi(input[2]);
    def = std::stoi(input[3]);
    weight = std::stoi(input[4]);
    
    std::istringstream(input[5]) >> std::boolalpha >> is_offensive;
    std::istringstream(input[6]) >> std::boolalpha >> has_effect;

    power = std::stoi(input[7]);
    accuracy = std::stoi(input[8]);
    mobility = std::stoi(input[9]);
    crit = std::stoi(input[10]);
    cooldown = std::stoi(input[11]);
    
    effect = input[12];
    eff_desc = input[13];
    desc = input[14];

}

head::head(std::vector<std::string> input
) : part(input) {
    clutch = std::stoi(input[15]);
    uses = std::stoi(input[16]);

}

arm::arm(std::vector<std::string> input
) : part(input) {
}

bottom::bottom(std::vector<std::string> input
) : part(input) {
    dodge = std::stoi(input[15]);
    speed = std::stoi(input[16]);
    acceleration = std::stoi(input[17]);
    friction = std::stoi(input[18]);
    endurance = std::stoi(input[19]);
}

char part::get_part_class() const {return part_class;}
std::string part::get_code() const {return code;}
std::string part::get_part_name() const {return part_name;}
int part::get_hp() const {return hp;}
int part::get_def() const {return def;}
int part::get_weight() const {return weight;}

bool part::get_is_offensive() const {return is_offensive;}
bool part::get_has_effect() const {return has_effect;}

int part::get_power() const {return power;}
int part::get_accuracy() const {return accuracy;}
int part::get_mobility() const {return mobility;}
int part::get_crit() const {return crit;}
int part::get_cooldown() const {return cooldown;}

std::string part::get_eff() const {return effect;}
std::string part::get_eff_desc() const {return eff_desc;}
std::string part::get_desc() const {return desc;}

int head::get_clutch() const {return clutch;}
int head::get_uses() const {return uses;}

int bottom::get_dodge() const {return dodge;}
int bottom::get_speed() const {return speed;}
int bottom::get_acceleration() const {return acceleration;}
int bottom::get_friction() const {return friction;}
int bottom::get_endurance() const {return endurance;}
