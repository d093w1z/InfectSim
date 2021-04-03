#include "MobilityModel.hpp"

class RandomWalkModel: private MobilityModel
{
	RandomWalkModel();
	void move(Human & h);
};