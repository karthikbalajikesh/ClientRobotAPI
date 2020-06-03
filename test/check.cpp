#include"Client.h"





int main(){

  Client A;
  namedWindow("Hello",WINDOW_NORMAL);
  imshow("Hello",A.detector.originalFrame);
  waitKey(0);  

  return 0;
}
