#ifndef PROCESSOR_H
#define PROCESSOR_H

class Processor {
 public:
  Processor(){
  cpu_ = Utilization();
  }
  
  float Utilization();  // TODO: See src/processor.cpp
  // DONE: Declare any necessary private members
 private:
 int prevIdle_{0};
 int prevNonIdle_{0};
 float cpu_;
};

#endif