# Client Side program for Wheeled Robots

This is the client program that will run on the Jetson Nano Platform which will communicate with a server by the likes of another ubuntu system. The program will do the following functions:

* Receive Realsense Camera Inputs

* Perform Lane Detection and receive Lane Points in space.

* Append to vector of obstacles.

* Serialize vector and send to server via TCP

* Communicate with Arduino serial (will be added later) 
