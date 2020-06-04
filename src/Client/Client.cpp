#include"Client.h"

// Client Constructor

Client::Client():DepthCamera(){
    detector = LaneDetector(this->ColorFrame);
    //extractIntrinsics();

}

void Client::detect(){
  
}

void Client::extractIntrinsics(){
    rs2::stream_profile profile = videoptr->get_profile();
    rs2::video_stream_profile video_profile = profile.as<rs2::video_stream_profile>();
    //rs2_intrinsics temp = video_profile.get_intrinsics();
    //Intrinsics = &temp;
}
// Check for the max and min depth to include in the obstacle list
void Client::updateObstacles(){
  // we will need to get the coordinates of the obstacles and append to the
  // vector of coordinates.
  pair<float,float> coordinate;
  float xcood = 0, zcood = 0;  // To hold the coordinate values
  int v = height/2; // pixel coordinates
  for(int u=0; u<width ; u++){
    // we need to get the depth at that point and then find the x and z coordinates
    zcood = depthptr->get_distance(u,v);
    if (zcood>0.48 && zcood<=3){
        // get the x coordinate and add to vector of obstacles.
        coordinate = getCoordinates(Intrinsics,u,v,zcood);
        Obstacles.push_back(coordinate);
    }
  }
}

void Client::updateLane(){


}
// Coordinate is needed in z,x format.
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
}
