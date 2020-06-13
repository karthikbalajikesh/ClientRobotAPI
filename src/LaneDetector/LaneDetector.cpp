// Lane Detector Class Methods
// Author - Karthik Balaji Keshavamurthi


#include<iostream>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/opencv.hpp>
#include<string>
#include"LaneDetector.h"

using namespace std;
using namespace cv;

LaneDetector::LaneDetector(){

} // empty constructor

LaneDetector::LaneDetector(Mat &Frame):originalFrame(Frame){
// This will be the main function
	setPointsTest();
	calculatePerspectiveMatrices();

}

void LaneDetector::setPoints(){
// Function to set the source and destination points for IPM
	sourceVertices[0] = Point(700,605);
	sourceVertices[1] = Point(890,605);
	sourceVertices[2] = Point(1760, 1030);
	sourceVertices[3] = Point(20, 1030);

//destination will be 640x480 img
	destinationVertices[0] = Point(0,0);
	destinationVertices[1] = Point(640,0);
	destinationVertices[2] = Point(640,480);
	destinationVertices[3] = Point(0,480);
}

void LaneDetector::setPointsTest(){
// Function to set the source and destination points for IPM
	sourceVertices[0] = Point(110,480);
	sourceVertices[1] = Point(260,120);
	sourceVertices[2] = Point(410,120);
	sourceVertices[3] = Point(560,480);


//destination will be 640x480 img
	destinationVertices[0] = Point(0,480);
	destinationVertices[1] = Point(0,0);
	destinationVertices[2] = Point(640,0);
	destinationVertices[3] = Point(640,480);

}

void LaneDetector::show(Mat &frame, string &window_name){
	// Function will create a normal window and display required
	// frame.
	const string wind = window_name;
	namedWindow(wind,WINDOW_NORMAL);
	imshow(wind,frame);
	waitKey(0);
}

void LaneDetector::calculatePerspectiveMatrices(){
	perspectiveMatrix = getPerspectiveTransform(sourceVertices,
		destinationVertices);
	invert(perspectiveMatrix,InversePerspectiveMatrix);
}

void LaneDetector::GenerateWarpedImage(){

	BirdsEyeView = Mat(480,640, CV_8UC3);
	warpPerspective(originalFrame,BirdsEyeView,perspectiveMatrix,
		BirdsEyeView.size(),INTER_LINEAR, BORDER_CONSTANT);
}

vector<Point2f> LaneDetector::slidingWindow(Mat image, Rect window)
{		// code adapted from :
		//https://github.com/JanHalozan/LaneDetector
    vector<Point2f> points;
    const Size imgSize = image.size();
    bool shouldBreak = false;

    while (true)
    {
        float currentX = window.x + window.width * 0.5f;

        Mat roi = image(window); //Extract region of interest
        vector<Point2f> locations;

        findNonZero(roi, locations); //Get all non-black pixels. All are white in our case

        float avgX = 0.0f;

        for (int i = 0; i < locations.size(); ++i) //Calculate average X position
        {
            float x = locations[i].x;
            avgX += window.x + x;
        }

        avgX = locations.empty() ? currentX : avgX / locations.size();

        Point point(avgX, window.y + window.height * 0.5f);
        points.push_back(point);

        //Move the window up
        window.y -= window.height;

        //For the uppermost position
        if (window.y < 0)
        {
            window.y = 0;
            shouldBreak = true;
        }

        //Move x position
        window.x += (point.x - currentX);

        //Make sure the window doesn't overflow, we get an error if we try to get data outside the matrix
        if (window.x < 0)
            window.x = 0;
        if (window.x + window.width >= imgSize.width)
            window.x = imgSize.width - window.width - 1;

        if (shouldBreak)
            break;
    }

    return points;
}

// Function to process the image
void LaneDetector::ProcessImage(){
	/* This Function is to process the Image obtained 
		after getting the Warped Image. 
		The following is done. 
		1. Convert to Grayscale. 
		2. Extract White Color
		3. Apply Guassian Blur to smoothen
		4. Denoise the image by Morph Open and Close. */
	cvtColor(BirdsEyeView,processedIPM, COLOR_BGR2GRAY);
	// create mask for capturing white
	// Parameter to tune - THreshold VALUES
	inRange(processedIPM,Scalar(150,150,150), Scalar(255,255,255),
							processedIPM);
	// Apply Gaussian Blur
	GaussianBlur(processedIPM,processedIPM,Size(9,9),0,0);
	// We remove noise and close the structures by
	// Morph open and close.
	MorphologyKernel = Mat::ones(5,5, CV_8U);
	morphologyEx(processedIPM, processedIPM, MORPH_OPEN, MorphologyKernel);
  morphologyEx(processedIPM, processedIPM, MORPH_CLOSE, MorphologyKernel);
	// convert to binary
	threshold(processedIPM, processedIPM, 150, 255, THRESH_BINARY);
	
}

void LaneDetector::Detect(Mat &frame){
	/* This function is the Final Detection function.
		It will perform Lane detection on a given Frame. 

		Input - Frame (CV::MAT)
		Output - LanePointsLeftFrame and LanePointsRightFrame

	*/
	originalFrame = frame;
	GenerateWarpedImage();
	
	ProcessImage();

	DetectLeftandRight();
}

// Function to only detect left and right points 
// and append to the vector of Left and Right points 
// in the vehicle frame.
void LaneDetector::DetectLeftandRight(){
	// Do the sliding window search for left
	vector<Point2f> LanePointsleft = slidingWindow(processedIPM,
		Rect(20, 440, 60, 40));
	//  Sliding Window Search for the right frame
	vector<Point2f> LanePointsright = slidingWindow(processedIPM,
		Rect(540, 440, 60, 40));
	// Now append to the left and Right vectors in vehicle frame
	cv::perspectiveTransform(LanePointsleft,LanePointsLeftFrame,
		InversePerspectiveMatrix);
	cv::perspectiveTransform(LanePointsright,LanePointsRightFrame,
		InversePerspectiveMatrix);
	
}

// Function to find the appended vector of lanes in the vehicle 
// coordinate system.
void LaneDetector::DetectOverall(){
	// Do the sliding window search for left
	vector<Point2f> LanePointsleft = slidingWindow(processedIPM,
		Rect(20, 440, 60, 40));
	//  Do the Sliding Window search for RIght
	vector<Point2f> LanePointsright = slidingWindow(processedIPM,
		Rect(540, 440, 60, 40));

	// Let us append both together
	LanePoints = LanePointsleft;
	LanePoints.insert(LanePoints.end(),LanePointsright.begin()
						, LanePointsright.end());
	cv::perspectiveTransform(LanePoints,LanePointsFrame,
		InversePerspectiveMatrix);
}
