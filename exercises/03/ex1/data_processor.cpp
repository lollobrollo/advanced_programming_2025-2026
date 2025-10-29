#include "data_processor.hpp"

DataProcessor::DataProcessor(double *data, int size) : size(size){
  this->data = new double[this->size];
  for(int i=0; i < this->size; ++i){
    this->data[i] = data[i];
  }
};

DataProcessor::DataProcessor(const DataProcessor &other) : size(other.size){
  this->data = new double[this->size];
  for(int i=0; i < this->size; ++i){
    this->data[i] = other.data[i];
  }
};

DataProcessor& DataProcessor::operator=(const DataProcessor& other){
  if(this!=&other){
    delete[] this->data;
    this->size = other.size;
    this->data = new double[this->size];
    std::copy(other.data, other.data + size, this->data);
  }
  return *this;
};

DataProcessor::~DataProcessor()
{
  delete[] this->data;
};

int DataProcessor::n_elements(){
  return this->size;
};

double DataProcessor::getMin() {
    double minVal = data[0];
    for (int i = 1; i < this->size; ++i)
        if (this->data[i] < minVal)
            minVal = this->data[i];
    return minVal;
}

double DataProcessor::getMax() {
    double maxVal = data[0];
    for (int i = 1; i < this->size; ++i)
        if (this->data[i] > maxVal)
            maxVal = this->data[i];
    return maxVal;
}

double DataProcessor::getMean() {
    double sum = 0.0;
    for (int i = 0; i < size; ++i)
        sum += data[i];
    return sum / size;
}

double DataProcessor::getStdDev() {
    double mean = this->getMean();
    double variance = 0.0;

    for (int i = 0; i < size; ++i)
        variance += std::pow(data[i] - mean, 2);

    variance /= size;
    return std::sqrt(variance);
}

std::ostream& operator<<(std::ostream& os, const DataProcessor& dp) {
  for (int i = 0; i < dp.size; ++i) {
    os << dp.data[i];
    if (i < dp.size - 1)
      os << ", ";
  }
  return os;
}

double& DataProcessor::operator[](int index) {
  if (index < 0 || index >= size)
    throw std::out_of_range("Index out of range");
  return data[index];
}

const double& DataProcessor::operator[](int index) const {
  if (index < 0 || index >= size)
    throw std::out_of_range("Index out of range");
  return data[index];
}

DataProcessor DataProcessor::operator+(const DataProcessor& other) const {
    if (this->size != other.size) {
        std::cerr << "Error: cannot add DataProcessor objects of different sizes." << std::endl;
        return *this;
    }

    double* newData = new double[this->size];
    for (int i = 0; i < this->size; ++i) {
        newData[i] = this->data[i] + other.data[i];
    }

    DataProcessor result(newData, this->size);
    delete[] newData;
    return result;
}
