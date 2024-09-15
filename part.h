#ifndef PART
#define PART

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <sstream>

// https://stackoverflow.com/questions/34378607/defining-a-unique-function-for-each-object

class part {
public:
    part(std::vector<std::string> input);

    char get_part_class() const;
    std::string get_code() const;
    std::string get_part_name() const;

    int get_hp() const;
    int get_def() const;
    int get_weight() const;
    
    bool get_is_offensive() const;
    bool get_has_effect() const;
    int get_power() const;
    int get_accuracy() const;
    int get_mobility() const;
    int get_crit() const;
    int get_cooldown() const;
    
    std::string get_eff() const;
    std::string get_eff_desc() const;
    std::string get_desc() const;

private:
    char part_class;
    std::string code;
    std::string part_name;
    int hp;
    int def;
    int weight;

    bool is_offensive;
    bool has_effect;
    int power;
    int accuracy;
    int mobility;
    int crit;
    int cooldown;
    
    std::string effect;
    std::string eff_desc;
    std::string desc;
};

class head : public part {
public:
    head(std::vector<std::string> input);

    int get_clutch() const;
    int get_uses() const;
    
private:
    int clutch;
    int uses;
};

class arm : public part {
public:
    arm(std::vector<std::string> input);

private:
};

class bottom : public part {
public:
    bottom(std::vector<std::string> input);

    int get_dodge() const;
    int get_speed() const;
    int get_acceleration() const;
    int get_friction() const;
    int get_endurance() const;

private:
    int dodge;
    int speed;
    int acceleration;
    int friction;
    int endurance;
};

#endif