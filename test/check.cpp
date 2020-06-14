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

void testThreadPerformance(Client& A){
  auto start = high_resolution_clock::now();
  A.DetectnoThread();
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(stop - start);
  cout << "\n Duraion without thread is "<<
                duration.count()<<std::endl;

  start = high_resolution_clock::now();
  A.Detect();
  stop = high_resolution_clock::now();
  duration = duration_cast<milliseconds>(stop - start);
  cout << "\n Duraion with thread is "<<
                duration.count()<<std::endl;

}

void testSocket(Client &A){
  
   
    boost::asio::steady_timer t(*A.IO,boost::asio::chrono::milliseconds(100));

    while(1){
      A.Update();
      t.wait();
    }
  

}


int main(){

  Client A;
  testSocket(A);
  /*
  auto start = high_resolution_clock::now();
  A.DetectnoThread();
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(stop - start);
  cout << "\n"<<duration.count()<<std::endl;
  cout<<"\n\n The Size of obstacles are    "<<A.Lanes.size()<<endl;
  printvector(A.Lanes);

  //cout<<"\n\n The Size of obstacles are    "<<A.depths.size()<<endl;
  //printvector(A.depths);*/

  return 0;
}
