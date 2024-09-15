
#include "catalog.h"


void populate_catalog(
    std::unordered_map<std::string, head> & h_catalog,
    std::unordered_map<std::string, arm> & l_catalog,
    std::unordered_map<std::string, arm> & r_catalog,
    std::unordered_map<std::string, bottom> & b_catalog
) {
    
    std::string delimiter = ";";
    std::ifstream f("fd.txt");

    int i = 0;

    std::string s;
    while(std::getline(f,s)){
        
        size_t pos_start = 0, pos_end, delim_len = delimiter.length();
        std::string token;

        std::vector<std::string> input;

        while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
            token = s.substr (pos_start, pos_end - pos_start);
            pos_start = pos_end + delim_len;
            input.push_back(token);
        }

        if(i%4==0) h_catalog.insert(std::make_pair(input[0], head(input)));
        else if(i%4==1) l_catalog.insert(std::make_pair(input[0], arm(input)));
        else if(i%4==2) r_catalog.insert(std::make_pair(input[0], arm(input)));
        else if(i%4==3) b_catalog.insert(std::make_pair(input[0], bottom(input)));

        i++;
    }

}
