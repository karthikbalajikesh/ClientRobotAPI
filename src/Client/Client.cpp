#include"Client.h"

// Client Constructor

Client::Client():DepthCamera(){
    detector = LaneDetector(this->ColorFrame);



}


// This is the main function of the program to
//detect the obstacles and Lanes from Depth input
void Client::Detect(){
  // get the frame from the depth camera
  getFrame();
  // get the depth parameters
  depth_frame depth  = frames.get_depth_frame();
  // extract the Intrinsic matrix
  extractIntrinsics(depth);
  // Get lane Points
  std::thread th1(&Client::updateLane,this);
  // Get Obstacle Points
  std::thread th2(&Client::updateObstacles,this);
  // Join the threads
  th1.join();
  th2.join();
}


void Client::DetectnoThread(){
  // get the frame from the depth camera
  getFrame();
  // get the depth parameters
  depth_frame depth  = frames.get_depth_frame();
  // extract the Intrinsic matrix
  extractIntrinsics(depth);
  // Get lane Points
  updateLane();
  // Get Obstacle Points
  updateObstacles();

}


// Function to extract Intrinsics
void Client::extractIntrinsics(depth_frame& frame){
    rs2_intrinsics intr =
    frame.get_profile().as<rs2::video_stream_profile>().get_intrinsics();
    Intrinsics = intr;
    if(Intrinsics.model == RS2_DISTORTION_INVERSE_BROWN_CONRADY){
      std::cout<<"\n\n Hey Mama!!!!!\n\n";
    }
}

// Function to update Lane Points in coordinates (z,x) form
void Client::updateLane(){
  depth_frame depth = frames.get_depth_frame();
  detector.Detect(this->ColorFrame);
  Lanes.clear();
  float pixel[2];
  pair<float,float> coordinate;
  float zcood;
  for(auto point:detector.LanePointsFrame){
    pixel[0] = point.x;
    pixel[1] = point.y;
    zcood = depth.get_distance(pixel[0],pixel[1]);
    if (zcood>= 0.48 && zcood<=3){
        get3DCoordinates(coordinate,pixel,zcood);
        // get the x coordinate and add to vector of obstacles.
        Lanes.push_back(coordinate);
    }
  }
}

// Coordinate is needed in z,x format.
// Function to get the coordinates of the obstacles.
void Client::updateObstacles(){
    depth_frame depth = frames.get_depth_frame();
    Obstacles.clear();
    depths.clear();
    pair<float,float> coordinate;
    float pixel_cood[2]; // for deproject_pixel_to_point functions
    float point_cood[3]; // for deproject pixel_to_point functions
    float zcood = 0;
    pixel_cood[1] = height/2;
    for(int u=0; u<width ; u = u+10){

      // we need to get the depth at that point and then find the x and z coordinates
      pixel_cood[0] = u;
      zcood = depth.get_distance(pixel_cood[0],pixel_cood[1]);
      if (zcood>= 0.48 && zcood<=3){
          depths.push_back(zcood);
          get3DCoordinates(coordinate,pixel_cood,zcood);
          // get the x coordinate and add to vector of obstacles.
          //rs2_deproject_pixel_to_point(point_cood, &Intrinsics,pixel_cood, zcood);
          Obstacles.push_back(coordinate);
      }
    }
}

// Function to map from pixel to z,x coordinates in space
void Client::get3DCoordinates(pair<float,float>& cood,
  float pixel[2], float zcood){
    float x = (pixel[0] - Intrinsics.ppx) / Intrinsics.fx;
    //float y = (pixel[1] - Intrinsics.ppy) / intrinsics.fy;
    x = zcood * x;
    //y = zcood * y;
    cood  = make_pair(zcood,x);

  }
