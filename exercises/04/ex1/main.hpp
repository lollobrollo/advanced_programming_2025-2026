
#ifndef MAIN_HPP
#define MAIN_HPP

#include <vector>
#include <string>
#include <iostream>
#include <fstream>


class DataSource {
  private:
    std::string name;
    std::vector<double> data;
  public:
    void const displayInfo();
    virtual const void read_data() const = 0;
    
    DataSource(string input){
      this->name = input;
      this->data = new [2.0,3.0,4.0]; // dummy initialization
    }
    virtual ~DataSource(){
      delete[] this->data;
    }
  };

DataSource::displayInfo()
{
  for(int i : data.size()){
    std::cout << data[i] << " ";
  }
  std::cout << "\n";
}

class FileDataSource: public DataSource {
  public:
    FileDataSource(string input) {
      this->name = inpit;
      
      std::ifstream inputFile(input);
      if (!inputFile) {
        std::cerr << "Error: Could not open file.\n";
        return;
      }

      double number;
      while(inputFile >> number){
        this->data.push_back(number);
      }
      inputFile.close();
    }
}

class ConsoleDataSource: public DataSource {
    public:
      ConsoleDataSource() = default;
    
}


class DataTransformer{
  
}


#endif