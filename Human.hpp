#pragma once
#include <iostream>
#include "conf.hpp"

class Human{

	int mID;
	sf::CircleShape mShape;
	enum Status mStatus = Status::Vulnerable;
	sf::Vector2i mPos;

public:
	static int& sGetCount();
	sf::Vector2f getPos(){return mShape.getPosition();}
	void setStatus(enum Status);
	Human();
	~Human();
	void mRenderHuman(sf::RenderWindow&);
	void mMove(sf::Vector2i);
};

