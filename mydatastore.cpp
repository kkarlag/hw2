#include "mydatastore.h"
#include "util.h"
//constructor
MyDataStore::MyDataStore()
{
}
//deconstructor
MyDataStore::~MyDataStore()
{
  //need to delete products and users
  for(unsigned int i=0; i<products.size();i++)
  {
    delete products[i];
  }
  
  for(std::map<std::string, User*>::iterator it=users.begin(); it !=users.end(); ++it)
  { 
    delete it->second; 
  }
} 
void MyDataStore::addProduct(Product* p)
{
  //adding to vector
  products.push_back(p);
  //copy of keywords of the product onto a set
  std::set<std::string> pKeyword= p->keywords();
  //iterate through and check if its in map yet
  std::set<std::string>::iterator it;
  for(it=pKeyword.begin(); it !=pKeyword.end(); ++it)
  { 
    //checking to see if its in map
    if(keywordMap.find(*it)==keywordMap.end())
    {
      //empty set of products 
      std::set<Product*> found;
      //map element with keyword that it is on and set that you made
      keywordMap.insert(std::make_pair(*it,found));
    }
    //adding product
    keywordMap[*it].insert(p);
  }
}
void MyDataStore::addUser(User* u)
{
  //add user 
  //use getName() function from user.cpp
  users.insert(make_pair(u->getName(),u));
  //check if they have a cart in add to cart
}
void MyDataStore::addtoCart(std::string username, Product* p)
{
  //checking if valid username
  if(users.find(username)==users.end())
  {
    std::cout<< "Invalid Request"<< std::endl;
    return; //not valid
  }
  //checking if user has a cart
  if(userCarts.find(username)==userCarts.end())
  {
    //make an empty vector of products
    std::vector<Product*> ps;
    //inserting into map of usercarts
    //making a cart and adding to map for this username so it has a cart now
    userCarts.insert(make_pair(username, ps));
  }
    //adding the picked product into cart (given username)
    userCarts[username].push_back(p);
}
void MyDataStore::buyCart(std::string username)
{
  //note to self: make sure to edit balance
  //checking if username is valid
  if(users.find(username)==users.end())
  {
    std::cout<< "Invalid Username"<< std::endl;
    return;
  }
  //iterate through
  //return if theres no cart associated with username
  // std::map<std::string,std::vector<Product*>>::iterator it;
  // it=userCarts.find(username);
  // if(it==userCarts.end())
  // {
  //   return; 
  // }
  std::vector<Product*> cantBuy;
  //iterating through vector of products (aka cart of username)
    for (unsigned int b = 0; b < userCarts[username].size(); b++)
    {
        //make sure user can afford product and product is in stock
        if(userCarts[username][b]->getQty()>0 && 
        users[username]->getBalance() >= userCarts[username][b]->getPrice())
        { 
          //deducting balance of user
          users[username]->deductAmount(userCarts[username][b]->getPrice());
          //deducting quantity
          userCarts[username][b]->subtractQty(b);
        }
        //unable to buy Item
        else
        {
          cantBuy.push_back(userCarts[username][b]);
        }
    }
  
  //clearing the cart because it was bought 
   userCarts[username].clear();
  //adding back what they could not buy
   userCarts[username]= cantBuy;

}
void MyDataStore::viewCart(std::string username)
{
  //checking if valid username
  if(users.find(username)==users.end())
  {
    std::cout<< "Invalid Username"<< std::endl;
    return; //not valid
  }
  //store vector of products(associated with the username) in cart vector 
  std::vector<Product*> cart= userCarts[username];
  //iterate through vector cart and print 
  for(unsigned int i=0; i<cart.size();i++)
  {
    std::cout<<"Item "<< i+1<< std::endl;
    std::cout<<cart[i]->displayString()<< std::endl;
    //note to self: dont forget to edit display string, correct format
  }
}

std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type)
{
  std::set<Product*> current= keywordMap[terms[0]];
  //iterate over terms 
  for(std::vector<std::string>::iterator it=terms.begin(); it != terms.end(); ++it)
  { //check if terms is in keywordMap
    if(keywordMap.find(*it)!=keywordMap.end())
    {
      if(type==0) //and --> intersection
      { 
        current=setIntersection(current, keywordMap[*it]);
      }
      else //or -->union
      {
        current=setUnion(current, keywordMap[*it]); //returns a set
      }
    }
  }
  //convert set into vector 
  //loop through given set and push back products into the vector 
  std::vector<Product*> results; 
  
  for(std::set<Product*>::iterator it=current.begin(); it != current.end(); ++it)
  {
    results.push_back(*it);
  }
  return results;
}

void MyDataStore::dump(std::ostream& ofile)
{
    //database file stuff
    ofile<<"<products>"<< std::endl;
    //outputting product info
    for(unsigned int i=0; i < products.size(); i++)
    {
      products[i]->dump(ofile);
    }
    ofile << "</products>" << std::endl;

    ofile <<"<users>"<< std::endl;
    //outputting user info
    
    for(std::map<std::string,User*>::iterator it=users.begin(); it !=users.end(); ++it)
    { 
      it->second-> dump(ofile); 
    }

    ofile << "</users>" << std::endl;
}
