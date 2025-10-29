
#ifndef MAIN_HPP
#define MAIN_HPP

#include <algorithm> //access to copy
#include <cmath> //for power and sqare root

class DataProcessor
{
private:
    int size;
    double *data;
public:
  DataProcessor(double *data, int size);
  DataProcessor(const DataProcessor& other);
  DataProcessor& operator=(const DataProcessor& other);
  ~DataProcessor();

  friend std::ostream& operator<<(std::ostream& os, const DataProcessor& dp);
  double& operator[](int index);             // read/write
  const double& operator[](int index) const; // read-only
  DataProcessor operator+(const DataProcessor& other) const;

  int n_elements();
  double getMin();
  double getMax();
  double getMean();
  double getStdDev();
  
};



#endif