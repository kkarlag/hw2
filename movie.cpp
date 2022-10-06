#include <sstream>
#include <iomanip>
#include "movie.h"
#include "util.h"


//constructor
Movie::Movie(std::string category, std::string name, std::string genre, std::string rating, double price, int qty) 
: Product("clothing",name, price, qty){
  rating_=rating;
  genre_=genre;
}
//deconstructor
Movie::~Movie(){}

std::set<std::string> Movie::keywords() const{
  //create set of words
  set<std::string> keyWords;
  //adding to set
  keyWords= parseStringToWords(name_);
  //adding to set but just a searchable keyword
  keyWords.insert(genre_);
  return keyWords; 
}
std::string Movie::displayString() const{
  string output= name_ +"\n"+ "Genre: " +genre_+" Rating: "+rating_+
  " "+to_string(price_)+" "+ to_string(qty_)+" left."+"\n";
  return output;
}
void Movie::dump(std::ostream& os) const{
  os << category_ << "\n" << name_ << "\n" 
  << price_ << "\n" << qty_ << "\n"<<
  genre_<< "\n"<< rating_ <<endl;
  
}
std::string Movie::getGenre() {
	return genre_;
}
std::string Movie::getRating() {
	return rating_;
}