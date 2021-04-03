#include <iostream>
#include "utils.hpp"
#include "simObj.hpp"

int main(int argc, char const *argv[])
{
	simObj so;
	so.run();
	//std::cout << gChance(0.3);
	// std::cout<<"random between 1..0 float: " <<gRandom<float>();
	// std::cout<<"random between 100..0 int: " <<gRandom<int>(100);
	return 0;
}
