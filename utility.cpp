#include "utility.h"

#include <cmath>
#include <random>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <unordered_map>

double round5(double a) {
    return std::round(a * 100000) / 100000;
}
