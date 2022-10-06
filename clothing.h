#include <sstream>
#include <iomanip>
#include "product.h"


class Clothing : public Product {
public:
  Clothing(std::string category, std::string name,double price, int qty, std::string size, std::string brand);
  std::set<std::string> keywords() const;
  std::string displayString() const;
  void dump(std::ostream& os) const; 
  std::string getSize();
  std::string getBrand();
  ~Clothing();

protected:
std::string size_; std::string brand_;
}; 