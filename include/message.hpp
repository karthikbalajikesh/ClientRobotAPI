#include<iostream>
#include<fstream>
#include<vector>
#include<utility>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include<boost/serialization/serialization.hpp>
#include<boost/serialization/access.hpp>
#include<boost/serialization/vector.hpp>
#include<boost/serialization/utility.hpp>

using std::vector;
using std::cout;
using std::pair;
using std::endl;
#define mp std::make_pair

class message{
private:
  friend class boost::serialization::access;
  template<class Archive>
  void serialize(Archive &A, const unsigned int version){
      A & Coordinates;
      A & stop_sign;
  }
public:
  vector<pair<float,float>> Coordinates;
  int stop_sign;  // if 0, no stop sign.
  message(){}
  message(vector<pair<float,float>> &cood):Coordinates(cood),stop_sign(0){}

  void printVector(){
      for(auto x:Coordinates){
          cout<<"\n"<<x.first<<"\t"<<x.second;
      }
      cout<<std::endl;
  }
};
