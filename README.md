SLIC Test
=========

This is a small test of the [SLIC algorithm](http://ivrg.epfl.ch/research/superpixels) developed at EPFL, paired with the OpenCV library to display and save treated image files. At the moment, parameters are still hardcoded into the project as the final product should be completely different.

A few test images have been included in <code>build/res</code>. The image currently hardcoded in the project is <code>greatbarrierreef.jpg</code>.

**Note:** The <code>lib/SLIC.h</code> and <code>lib/SLIC.cpp</code> files have been slightly modified to fix a few problems. The *const* attribute has been removed (or commented out) from a few formal parameters and it is now possible to set the color for the superpixel borders.