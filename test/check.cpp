#include"Client.h"


void printvector(std::vector<pair<float,float>> A){
  for(auto x:A){

    std::cout<< "\nY = "<<x.first<<"\tX = "<<x.second;
  }
}

void printvector(std::vector<float> &data){
  for(auto x:data){
    std::cout<<"\n"<<x;
  }
}


int main(){

  Client A;
auto start = high_resolution_clock::now();
  A.detect();
  A.getPointCoordinates();
auto stop = high_resolution_clock::now();
auto duration = duration_cast<milliseconds>(stop - start);
cout << "\n"<<duration.count()<<std::endl;
  A.getPointCoordinates();
  cout<<"\n\n The Size of obstacles are    "<<A.Obstacles.size()<<endl;
  printvector(A.Obstacles);
  A.getPointCoordinates();
  //cout<<"\n\n The Size of obstacles are    "<<A.depths.size()<<endl;
  //printvector(A.depths);

  return 0;
}
