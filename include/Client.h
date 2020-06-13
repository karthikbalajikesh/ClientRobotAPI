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
  vector<pair<float,float>> Lanes; // not used
  vector<pair<float,float>> LanesLeft;
  vector<pair<float,float>> LanesRight;
  vector<float> depths;

  Client();

  void extractIntrinsics(rs2::depth_frame& frame);
  pair<float,float> getCoordinates(rs2_intrinsics * intrin,
     int u,int v, float depth);
  void updateObstacles();
  void updateLane();
  void updateLaneLeft();
  void updateLaneRight();
  void Detect();
  void DetectnoThread();
  void get3DCoordinates(pair<float,float>& cood,float pixel[2],float zcood);
};
