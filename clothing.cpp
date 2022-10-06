#include <sstream>
#include <iomanip>
#include "clothing.h"
#include "util.h"
using namespace std;

//constructor
Clothing::Clothing(std::string category, std::string name, std::string size, std::string brand, double price, int qty) 
: Product("clothing",name, price, qty){
  size_=size;
  brand_=brand;
}
//deconstructor
Clothing::~Clothing(){}

std::set<std::string> Clothing::keywords() const{
  //create set of words
  set<std::string> keyWords;
  //adding to set
  keyWords= parseStringToWords (name_+" " +brand_);
  //adding to set
  return keyWords; 
}
std::string Clothing::displayString() const{
string output= name_ +"\n"+ "Size: " +size_+" Brand: "+brand_+
" "+to_string(price_)+" "+ to_string(qty_)+" left."+"\n";
return output;
}
void Clothing::dump(ostream& os) const{
  os << category_ << "\n" << name_ << "\n" 
  << price_ << "\n" << qty_ << "\n"<<
  size_<< "\n"<< brand_ <<endl;
  //author and isbn
}
std::string Clothing::getSize() {
	return size_;
}
std::string Clothing::getBrand() {
	return brand_;
}