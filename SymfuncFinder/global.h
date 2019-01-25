#ifndef GLOBAL_H_
#define GLOBAL_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <array>
#include <vector>
#include <string>
#include <map>
#include "Parameter.h"

#ifndef EIGEN_USE_MKL_ALL
//#define EIGEN_USE_MKL_ALL
#endif // !EIGEN_USE_MKL_ALL

#define DEBUG_MODE
#define OUTPUT_TO_SCREEN

using std::endl;
using std::cout;
using std::setw;
using std::setprecision;
using std::istream;
using std::ostream;
using std::ofstream;
using std::ifstream;
using std::istringstream;
using std::ostringstream;
using std::array;
using std::vector;
using std::string;

constexpr double pi = 3.1415926535897932384;

extern Parameter parameter;
extern ofstream debug;


#endif // !GLOBAL_H_
