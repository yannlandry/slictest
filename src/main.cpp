// std
#include <iostream>

// cv
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

// other
#include "SLIC.h"
#include "SLIC_helpers.hpp"
#include "conversion.hpp"


int main(int argc, char* argv[]) {
	// Open an image in OpenCV
	cv::Mat image(cv::imread("res/greatbarrierreef.jpg"));
	unsigned int* buffer = new unsigned int[image.cols * image.rows]{};	// our SLIC buffer of pixels
	
	// Convert image in a compatible buffer
	unsigned int* cursor = buffer;
	for(int row = 0; row < image.rows; ++row) {
		cv::Vec3b* current = image.ptr<cv::Vec3b>(row);
		for(int col = 0; col < image.cols; ++col)
			CVtoSLIC(current[col], *(cursor++));
	}

	// Some input parameters
	const int desiredSuperpixels = 200,	// number of desired superpixels
			  compactness = 10;			// compactness factor of the superpixels

	// Output parameters
	int* superpixelData = nullptr;		// will recieve array to superpixel data
	int superpixelCount = 0;			// will recieve actual number of superpixels

	// SLIC object and segmentation function
	SLIC segment;
	segment.DoSuperpixelSegmentation_ForGivenNumberOfSuperpixels(
		buffer, image.cols, image.rows, superpixelData, superpixelCount, desiredSuperpixels, compactness);

	/*/ Optionally, save the data to a file (uncomment if needed)
	std::string filename("SLICgreatbarrierreef.dat");
	std::string savepath("res/data/");	// the file with superpixel data will be saved with filename in filepath
	segment.SaveSuperpixelLabels(klabels, width, height, filename, savepath);
	//*/

	// Draw the contours around the superpixels
	segment.DrawContoursAroundSegments(buffer, superpixelData, image.cols, image.rows, makeSLICPixel(255,255,0));
																				// pass color for borders, here yellow

	// Final OpenCV image to be displayed
	cv::Mat postSLIC(image.rows, image.cols, CV_8UC3, cv::Scalar(0));

	// Reconvert buffer with edges into an OpenCV image
	cursor = buffer;
	for(int row = 0; row < image.rows; ++row) {
		cv::Vec3b* current = postSLIC.ptr<cv::Vec3b>(row);
		for(int col = 0; col < image.cols; ++col)
			SLICtoCV(*(cursor++), current[col]);
	}

	// Display and save final image
	cv::imshow("Final with borders", postSLIC);
	cv::waitKey(0);

	cv::imwrite("res/SLIC_greatbarrierreef.jpg", postSLIC);

	return 0;
}