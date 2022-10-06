#include <string>
#include <set>
#include <map>
#include <vector>
#include <iterator>
#include "datastore.h"

class MyDataStore: public DataStore {
public:
    MyDataStore(); //constructor

    ~MyDataStore();//deconstructor

    //Adds a product to the data store
    void addProduct(Product* p);
    //Adds a user to the data store
    void addUser(User* u);
    void addtoCart(std::string username, Product* p);
    void buyCart(std::string username);
    void viewCart(std::string username);
    std::vector<Product*> search(std::vector<std::string>& terms, int type);
    void dump(std::ostream& ofile);

protected:
    //map: string to set of products 
    std::map<std::string, std::set<Product*>> keywordMap; //keyword to set of products
    std::vector<Product*> products;
    //map of strings to users 
    std::map<std::string, User*> users; 
    // map of string to vector of products--> userCarts
    std::map<std::string, std::vector<Product*>> userCarts; 
    // map of string to vector of products--> userCarts
};
