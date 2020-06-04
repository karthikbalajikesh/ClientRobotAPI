#include"Client.h"


void printvector(std::vector<pair<float,float>> A){
  for(auto x:A){

    std::cout<< "\nY = "<<x.first<<"\tX = "<<x.second;
  }
}


int main(){

  Client A;
  A.detect();
  namedWindow("Hello",WINDOW_NORMAL);
  imshow("Hello",A.ColorFrame);
  waitKey(0);
  cout<<"\n\n The Size of obstacles are    "<<A.Obstacles.size()<<endl;
  printvector(A.Obstacles);
  return 0;
}
