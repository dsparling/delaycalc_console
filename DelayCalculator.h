// DelayCalculator.h
#ifndef DELAYCALCULATOR_H
#define DELAYCALCULATOR_H

class DelayCalculator
{
  public:
  // default constructor
  DelayCalculator();
  DelayCalculator(int);
  // destructor
  ~DelayCalculator();
  // methods
  // calculate
  void calculateDelay();
  // delay 
  void printDelay();
  void writeDelay();
  // mutator
  void setBPM(int);
  void setPrecision(int);
  // accessor
  int getBPM();
  int getPrecision();
  // help/version/warranty
  void printHelp();
  void printVersion();
  void printWarranty();

  // data
  private:
    int bpm;
    int precision;
    // std
    double std_whole;
    double std_half;
    double std_quarter;
    double std_eigth;
    double std_sixteenth;
    double std_thirtysecond;
    // dotted
    double dotted_whole;
    double dotted_half;
    double dotted_quarter;
    double dotted_eigth;
    double dotted_sixteenth;
    double dotted_thirtysecond;
    // triplet
    double triplet_whole;
    double triplet_half;
    double triplet_quarter;
    double triplet_eigth;
    double triplet_sixteenth;
    double triplet_thirtysecond;
};

#endif // DELAYCALCULATOR_H
