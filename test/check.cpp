#include"Client.h"





int main(){

  Client A;
  namedWindow("Hello",WINDOW_NORMAL);
  imshow("Hello",A.detector.originalFrame);
  waitKey(0);
  cout<<"\n\n The Size of obstacles are    "<<A.Obstacles.size()<<endl;
  return 0;
}
