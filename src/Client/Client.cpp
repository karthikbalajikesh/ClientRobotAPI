#include"Client.h"

// Client Constructor

Client::Client():DepthCamera(){
  detector = LaneDetector(this->ColorFrame);

}
