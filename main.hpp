#pragma once

#include <iostream>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <string>
#include <algorithm>

#include "GcastUtils.cpp"
#include "Color.hpp"
#include "Image.hpp"
#include "Uinputs.hpp"
#include "Vec3.hpp"
#include "Raytrace.hpp"
#include "Object.hpp"
#include "HittableList.hpp"


using namespace std;
using std::make_shared;
using std::shared_ptr;

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

std::string getCurrentTime() {
    std::time_t t = std::time(nullptr);
    std::tm tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y%m%d_%H%M%S");
    return oss.str();
}