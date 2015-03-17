/* Verious helpers to work with the SLIC algorithm */

#ifndef SLIC_HELPERS_HPP
#define SLIC_HELPERS_HPP

#include <iostream>


/* Generate an unsigned int representing an ARGB pixel from
 * individual values */
unsigned int makeSLICPixel(int red, int green, int blue) {
	int slicpix = 0;
	unsigned char* cursor = reinterpret_cast<unsigned char*>(&slicpix);

	*(cursor+0) = 0;								// A
	*(cursor+1) = static_cast<unsigned char>(red);	// R
	*(cursor+2) = static_cast<unsigned char>(green);// G
	*(cursor+3) = static_cast<unsigned char>(blue);	// B

	return slicpix;
}


/* Print an ARGB pixel, mainly for debug purposes */
void printBufferPixel(unsigned int pixel) {
	unsigned char* ptr = reinterpret_cast<unsigned char*>(&pixel);

	std::cout << '[' << static_cast<unsigned int>(*ptr)
		 << ", " << static_cast<unsigned int>(*(ptr+1))
		 << ", " << static_cast<unsigned int>(*(ptr+2))
		 << ", " << static_cast<unsigned int>(*(ptr+3)) << ']';
}


#endif