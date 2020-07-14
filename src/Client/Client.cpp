#include"Client.h"

// Client Constructor

Client::Client():DepthCamera(),TCP(){
    detector = LaneDetector(this->ColorFrame);
    Data = message();

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
  Data.setParams(Obstacles,LanesLeft,LanesRight);
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
  Data.setParams(Obstacles,LanesLeft,LanesRight);
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

  detector.Detect(this->ColorFrame);
  updateLaneLeft();
  updateLaneRight();
}

void Client::updateLaneLeft(){
  // Function to get spatial coordinates of Left lane pts
  depth_frame depth = frames.get_depth_frame();
  LanesLeft.clear();
  float pixel[2];
  pair<float,float> coordinate;
  float zcood;
  for(auto point:detector.LanePointsLeftFrame){
    pixel[0] = point.x;
    pixel[1] = point.y;
    zcood = depth.get_distance(pixel[0],pixel[1]);
    if (zcood>= 0.48 && zcood<=3){
        get3DCoordinates(coordinate,pixel,zcood);
        // get the x coordinate and add to vector of obstacles.
        LanesLeft.push_back(coordinate);
    }
  }
}

void Client::updateLaneRight(){
  depth_frame depth = frames.get_depth_frame();
  LanesRight.clear();
  float pixel[2];
  pair<float,float> coordinate;
  float zcood;
  for(auto point:detector.LanePointsRightFrame){
    pixel[0] = point.x;
    pixel[1] = point.y;
    zcood = depth.get_distance(pixel[0],pixel[1]);
    if (zcood>= 0.48 && zcood<=3){
        get3DCoordinates(coordinate,pixel,zcood);
        // get the x coordinate and add to vector of obstacles.
        LanesRight.push_back(coordinate);
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
// Function to send request message, Message object to Server
void Client::sendToServer(){
  
  boost::asio::streambuf buf;
  std::ostream OutputStream(&buf);
  boost::archive::text_oarchive OutputArchive(OutputStream);

  // Perform Serialization
  OutputArchive & Data;

  // Scatter Send
  const size_t header = buf.size();
  vector<boost::asio::const_buffer> buffers;
  buffers.push_back(boost::asio::const_buffer(&header, sizeof(header)));
        buffers.push_back(buf.data());
  boost::asio::write(*SOCK,buffers);

  SOCK->shutdown(boost::asio::socket_base::shutdown_send);
}

void Client::receiveFromServer(){
  size_t header;
  boost::asio::read(*SOCK,
      boost::asio::buffer( &header, sizeof(header)));

  // Read the Body
  boost::asio::streambuf buf;
  boost::asio::read(*SOCK,buf.prepare(header));
  buf.commit(header);
  // Deserialization
  std::istream InputStream(&buf);
  boost::archive::text_iarchive InputArchive(InputStream);
  InputArchive & Trajectory;

}
// This function will run on a loop.
void Client::Update(){
  SOCK->connect(*EP);
  Detect();
  sendToServer();
  receiveFromServer();
  Trajectory.printDetails();
  SOCK->close();
  /* After this we will send to another program
  which will communicate this to a server that
  communicates with Arduino using serial communication.*/
}
