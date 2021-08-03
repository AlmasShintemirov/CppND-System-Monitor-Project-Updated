#include <string>
#include "format.h"
#include <iostream>
#include <sstream>
#include <iomanip>
using std::string;
using std::to_string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) { 
  long hh, mm, ss;
  hh = seconds / 3600;
  mm = seconds % 3600 / 60;
  ss = seconds % 3600 % 60;
  std::stringstream time;
  time << std::setfill('0') << std::setw(2) << hh << ":" << mm << ":" << ss;
  return time.str();
}

