#include <iostream>
#include <string>
#include <vector>
#include <numeric> // contains accumulate()
 
class Product {
public:
  std::string name;
  double price;
};

void print(const std::vector<Product> &products) {
  for (const Product &product : products) {
    std::cout << product.name << ":\t$" << product.price << std::endl;
  }
}

int main() {
  // Define a list of products.
  const std::vector<Product> products = {{"Smartphone", 799.99},
                                         {"Laptop", 1299.99},
                                         {"Tablet", 349.99},
                                         {"Headphones", 99.99},
                                         {"Smartwatch", 249.99}};

  std::cout << "List of products:" << "\n";
  print(products);

  // Compute total cost.
  auto my_sum = [](const double lhs, const Product& rhs) {
    double sum = lhs + rhs.price;
    std::cout << lhs <<" + " << rhs.price << " = " << sum << "\n";
    return sum;
};


  double total = std::accumulate(products.begin(), products.end(), 0.0, my_sum);
  std::cout << "Final result: " << total << "\n";

  return 0;
}
