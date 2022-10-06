#include <sstream>
#include <iomanip>
#include "product.h"


class Book : public Product {
public:
	Book(std::string category,std::string name,double price, int qty, std::string ISBN,std::string author);
  ~Book(); 
  std::set<std::string> keywords() const;
  std::string displayString() const;
  void dump(std::ostream& os) const; 
  std::string getISBN();
  std::string getAuthor();

protected:
std::string ISBN_; std::string author_;
}; 
