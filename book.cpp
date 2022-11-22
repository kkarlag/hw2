#include <sstream>
#include <iomanip>
#include "book.h"
#include "util.h"
using namespace std;

//constructor

Book::Book(std::string category, std::string name, double price, int qty, std::string ISBN, std::string author) 
: Product("book",name, price, qty){
  ISBN_=ISBN;
  author_=author;
}
//deconstructor
Book::~Book(){}

std::set<string> Book::keywords() const{
  //create set of words
  std::set<std::string> keyWords;
  //adding to set
  keyWords= parseStringToWords (name_+" " +author_);
  //adding to set
  keyWords.insert(ISBN_);
  return keyWords; 
}
string Book::displayString() const{
  string output= name_ +"\n"+ "Author: " +author_+" ISBN: "+ISBN_+"\n"+to_string(price_)+" "+ to_string(qty_)+" left."+"\n";
  return output;
}
void Book::dump(ostream& os) const{
  os << category_ << "\n" << name_ << "\n" 
  << price_ << "\n" << qty_ << "\n"<<
  ISBN_<< "\n"<< author_ <<endl;
  //author and isbn
}
std::string Book::getISBN() {
	return ISBN_;
}
std::string Book::getAuthor() {
	return author_;
}


