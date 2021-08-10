#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include "process.h"
#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;
using std::cout;
using std::stoi;



// DONE: Return this process's ID
int Process::Pid() { 
    return pid_;
}

// DONE: Return this process's CPU utilization
float Process::CpuUtilization() const { 
  float cpu_usage{0.0};
  vector<string> proc_data = LinuxParser::ProcessCpuUtilization(this->pid_);
  if (proc_data.size() == 22){
    long total_time = stol(proc_data[13]) + stol(proc_data[14]) + stol(proc_data[15]) + stol(proc_data[16]);
    long seconds = LinuxParser::UpTime() - LinuxParser::UpTime(this->pid_);
    cpu_usage = (float) (total_time / sysconf(_SC_CLK_TCK)) / seconds; 
  }
  return cpu_usage;
}
/*
#14 utime - CPU time spent in user code, measured in clock ticks
#15 stime - CPU time spent in kernel code, measured in clock ticks
#16 cutime - Waited-for children's CPU time spent in user code (in clock ticks)
#17 cstime - Waited-for children's CPU time spent in kernel code (in clock ticks)
#22 starttime - Time when the process started, measured in clock ticks
Hertz (number of clock ticks per second) of your system.
In most cases, getconf CLK_TCK can be used to return the number of clock ticks.
The sysconf(_SC_CLK_TCK) C function call may also be used to return the hertz value.

total_time = utime + stime
total_time = total_time + cutime + cstime
seconds = uptime - (starttime / Hertz)
cpu_usage = 100 * ((total_time / Hertz) / seconds)
*/

// DONE: Return the command that generated this process
string Process::Command() { 
    return LinuxParser::Command(this-> pid_); 
}

// DONE: Return this process's memory utilization
string Process::Ram() { 
    return LinuxParser::Ram(this->pid_); 
}

// DONE: Return the user (name) that generated this process
string Process::User() { 
    return LinuxParser::User(this->pid_);
}

// DONE: Return the age of this process (in seconds)
long int Process::UpTime() { 
    //cout << "Process Up time: " << LinuxParser::UpTime(this->pid_) << "/n";
    return LinuxParser::UpTime(this->pid_); 
}

// DONE: Overload the "less than" comparison operator for Process objects
bool Process::operator<(Process const& a) const { 
   return (this->CpuUtilization() > a.CpuUtilization());
}
