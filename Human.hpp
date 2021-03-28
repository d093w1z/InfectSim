#pragma once
#include <iostream>
#include "conf.hpp"

class Human{

	int mID;
	static int sID;
	enum Status mStatus = Status::Vulnerable;

public:
	Human(){mID = ++sID;}
	void move(){std::cout << mID<<" moved!"<<std::endl;}
	void getCount(){std::cout<<sID<<std::endl;}
};

int Human::sID = 0;