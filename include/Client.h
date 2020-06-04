#ifndef CLIENT_H
#define CLIENT_H
#endif

#include<iostream>
#include<vector>
#include<utility> // for std::pair
#include<string>
#include<algorithm>
#include"depthCamera.h"
#include"LaneDetector.h"



using std::vector;
using std::pair;


class Client: public DepthCamera {
public:
  // This will contain one instance of Lane LaneDetector
  LaneDetector detector;
  rs2_intrinsics Intrinsics;
  vector<pair<float,float>> Obstacles;
  vector<float> depths;

  Client();
  void getPointCoordinates();
  void extractIntrinsics(rs2::depth_frame& frame);
  pair<float,float> getCoordinates(rs2_intrinsics * intrin,
     int u,int v, float depth);
  void updateObstacles(depth_frame* depthpointer);
  void updateLane();
  void detect();
  void get3DCoordinates(pair<float,float>& cood,float pixel[2],float zcood);
};
