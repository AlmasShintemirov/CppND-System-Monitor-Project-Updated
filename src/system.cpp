#include <unistd.h>
#include <cstddef>
#include <set>
#include <string>
#include <vector>
#include <iostream>

#include "process.h"
#include "processor.h"
#include "system.h"
#include "linux_parser.h"
#include <algorithm>


using std::set;
using std::size_t;
using std::string;
using std::vector;
using std::cout;

// DONE: Return the system's CPU
Processor& System::Cpu() {   
    return cpu_;
}

// DONE: Return a container composed of the system's processes
vector<Process>& System::Processes() { 
    processes_.clear();
    for (int pid : LinuxParser::Pids()){
        Process process(pid);
        processes_.push_back(process);
    }
    std::sort(std::begin(processes_), std::end(processes_));
    return processes_;
}

// DONE: Return the system's kernel identifier (string)
std::string System::Kernel() { 
    return LinuxParser::Kernel(); 
}

// DONE: Return the system's memory utilization
float System::MemoryUtilization() { 
    return LinuxParser::MemoryUtilization(); 
}

// DONE: Return the operating system name
std::string System::OperatingSystem() { 
    return LinuxParser::OperatingSystem();
}

// DONE: Return the number of processes actively running on the system
int System::RunningProcesses() { 
    return LinuxParser::RunningProcesses();
}

// DONE: Return the total number of processes on the system
int System::TotalProcesses() { 
    return LinuxParser::TotalProcesses();
}

// DONE: Return the number of seconds since the system started running
long System::UpTime() { 
    return LinuxParser::UpTime();
}