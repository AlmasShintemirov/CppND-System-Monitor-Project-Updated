#include "processor.h"
#include "linux_parser.h"
#include <string>

using std::string;

// DONE: Return the aggregate CPU utilization
void Processor::ReadData(int& Idle, int& NonIdle){
  string line;
  string key;
  int cpu_data[10] = {};
  std::ifstream filestream(LinuxParser::kProcDirectory + LinuxParser::kStatFilename);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::istringstream linestream(line);
      while (linestream >> key ) {
        if (key == "cpu") {
          for (int &data : cpu_data) {
             linestream >> data;
          } 
          break;
        }
      //     user    nice   system  idle      iowait irq   softirq  steal  guest  guest_nice
      //cpu  74608   2520   24433   1117073   6176   4054  0        0      0      0 
      Idle = cpu_data[3] + cpu_data[4];
      NonIdle = cpu_data[0] + cpu_data[1] + cpu_data[2] + cpu_data[5] + cpu_data[6] + cpu_data[7];
      }
    }
  }
}

float Processor::Utilization() {
  int Idle, NonIdle;
  Processor::ReadData(Idle, NonIdle);
  //differentiate: actual value minus the previous one
  int totald = (Idle + NonIdle) - (prevIdle_ + prevNonIdle_);
  int idled = Idle - prevIdle_;
  float CPU_Percentage = (float) (totald - idled)/totald;
  prevIdle_ = Idle;
  prevNonIdle_ = NonIdle;
  return CPU_Percentage;
}
