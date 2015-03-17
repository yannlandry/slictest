all:
	g++ src/main.cpp lib/SLIC.cpp -I./lib/ -I./src/include/ `pkg-config opencv --libs` -std=c++11 -o ./build/SLICTest