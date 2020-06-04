#include"Client.h"

// Client Constructor

Client::Client():DepthCamera(){
    detector = LaneDetector(this->ColorFrame);



}

void Client::detect(){
  getFrame();
  //depth_frame temp = frames.get_depth_frame();
  //depthptr = &temp;
  //updateObstacles(depthptr);
}

void Client::extractIntrinsics(depth_frame& frame){
    rs2_intrinsics intr =
    frame.get_profile().as<rs2::video_stream_profile>().get_intrinsics();
    Intrinsics = intr;
    if(Intrinsics.model == RS2_DISTORTION_INVERSE_BROWN_CONRADY){
      std::cout<<"\n\n Hey Mama!!!!!\n\n";
    }
}
// Check for the max and min depth to include in the obstacle list
/*
void Client::updateObstacles(depth_frame* depthpointer){
  // we will need to get the coordinates of the obstacles and append to the
  // vector of coordinates.
  Obstacles.clear();
  pair<float,float> coordinate;
  float xcood = 0, zcood = 0;  // To hold the coordinate values
  int v = height/2; // pixel coordinates
  for(int u=0; u<width ; u++){
    // we need to get the depth at that point and then find the x and z coordinates
    zcood = depthpointer->get_distance(u,v);
    if (zcood>0.48 && zcood<=3){
        // get the x coordinate and add to vector of obstacles.
        coordinate = getCoordinates(Intrinsics,u,v,zcood);
        Obstacles.push_back(coordinate);
    }
  }
}*/

void Client::updateLane(){


}
// Coordinate is needed in z,x format.
/*
pair<float,float> Client::getCoordinates(rs2_intrinsics * intrin,
   int u,int v, float depth)
{
    // adapted from rs2::deproject_pixel_to_point();
    float x = (u - intrin->ppx) / intrin->fx;
    float y = (v - intrin->ppy) / intrin->fy;
    float z = depth;
    if(intrin->model == RS2_DISTORTION_INVERSE_BROWN_CONRADY)
    {
        float r2  = x*x + y*y;
        float f = 1 + intrin->coeffs[0]*r2 + intrin->coeffs[1]*r2*r2 + intrin->coeffs[4]*r2*r2*r2;
        float ux = x*f + 2*intrin->coeffs[2]*x*y + intrin->coeffs[3]*(r2 + 2*x*x);
        float uy = y*f + 2*intrin->coeffs[3]*x*y + intrin->coeffs[2]*(r2 + 2*y*y);
        x = ux;
        y = uy;
    }
    x = depth * x;
    pair<float,float> coordinate  = make_pair(z,x);
    return coordinate;
}*/

// Function to get the coordinates of the obstacles. 
void Client::getPointCoordinates(){
    rs2::depth_frame depth = frames.get_depth_frame();
    extractIntrinsics(depth);
    Obstacles.clear();
    depths.clear();
    pair<float,float> coordinate;
    float pixel_cood[2]; // for deproject_pixel_to_point functions
    float point_cood[3]; // for deproject pixel_to_point functions
    float zcood = 0;
    pixel_cood[1] = height/2;


    for(int u=0; u<width ; u++){

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

void Client::get3DCoordinates(pair<float,float>& cood,
  float pixel[2], float zcood){
    float x = (pixel[0] - Intrinsics.ppx) / Intrinsics.fx;
    //float y = (pixel[1] - Intrinsics.ppy) / intrinsics.fy;
    x = zcood * x;
    //y = zcood * y;
    cood  = make_pair(zcood,x);

  }
