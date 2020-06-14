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

typedef std::pair<float,float> floatpair;
// Class that contains the response sent from Server
// This is the path that needs to be followed by the 
// robot
class Path{
private:
    friend class boost::serialization::access;
  template<class Archive>
  void serialize(Archive &A, const unsigned int version){
      A & Waypoints;
  }
public:
vector<floatpair> Waypoints;

Path(){}

void setParams(vector<floatpair> &Cood){
    Waypoints = Cood;
}
};