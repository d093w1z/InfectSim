#pragma once
#include "Human.hpp"

class MobilityModel{
	MobilityModel();
	virtual void move(Human & h) = 0;
};