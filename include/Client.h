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
  vector<pair<float,float>> Obstacles;

  Client();

};
