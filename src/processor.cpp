#include "processor.h"
#include "linux_parser.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

// DONE: Return the aggregate CPU utilization
float Processor::Utilization() {
  vector<int> cpu_data = LinuxParser::CpuUtilization();
  //Processor::ReadData(Idle, NonIdle);
  //     user    nice   system  idle      iowait irq   softirq  steal  guest  guest_nice
  //cpu  74608   2520   24433   1117073   6176   4054  0        0      0      0 
  int Idle = cpu_data[3] + cpu_data[4];
  int NonIdle = cpu_data[0] + cpu_data[1] + cpu_data[2] + cpu_data[5] + cpu_data[6] + cpu_data[7];
  
  //differentiate: actual value minus the previous one
  int totald = (Idle + NonIdle) - (prevIdle_ + prevNonIdle_);
  int idled = Idle - prevIdle_;
  float CPU_Percentage = (float) (totald - idled)/totald;
  prevIdle_ = Idle;
  prevNonIdle_ = NonIdle;
  return CPU_Percentage;
}
