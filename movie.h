#include <sstream>
#include <iomanip>
#include "product.h"
using namespace std;

class Movie : public Product {
public:
  Movie(std::string category, std::string name, double price, int qty, std::string genre, std::string rating);
  std::set<std::string> keywords() const;
  std::string displayString() const;
  void dump(std::ostream& os) const; 
  std::string getGenre();
  std::string getRating();
  ~Movie();
protected:
string genre_; string rating_;
}; 
