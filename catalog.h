#ifndef CATALOG
#define CATALOG

#include <string>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "part.h"

void populate_catalog(
    std::unordered_map<std::string, head> & h_catalog,
    std::unordered_map<std::string, arm> & l_catalog,
    std::unordered_map<std::string, arm> & r_catalog,
    std::unordered_map<std::string, bottom> & b_catalog
);


#endif
