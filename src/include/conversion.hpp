/* Functions to allow conversion from SLIC
 * pixels to OpenCV pixels and back */

#ifndef CONVERSION_HPP
#define CONVERSION_HPP

#include <opencv2/core/core.hpp>


/* Converts a cv::Vec3b (from OpenCV) to an unsigned int
 * compatible with the SLIC algorithm */
void CVtoSLIC(cv::Vec3b& vector, unsigned int& slicpix) {
	unsigned char* cursor = reinterpret_cast<unsigned char*>(&slicpix);

	*(cursor+0) = 0;		// A
	*(cursor+1) = vector[2];// R
	*(cursor+2) = vector[1];// G
	*(cursor+3) = vector[0];// B
}


/* Converts an unsigned int compatible with the SLIC algorithm
 * to a cv::Vec3b (from OpenCV) */
void SLICtoCV(unsigned int slicpix, cv::Vec3b& vector) {
	unsigned char* cursor = reinterpret_cast<unsigned char*>(&slicpix);

	// no A data			// A
	vector[2] = *(cursor+1);// R
	vector[1] = *(cursor+2);// G
	vector[0] = *(cursor+3);// B
}


#endif