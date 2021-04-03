#pragma once
#include <iostream>
#include "conf.hpp"

class Human{
	int mID;
	sf::CircleShape mShape;
	sf::RectangleShape mWay;
	enum Status mStatus = Status::Vulnerable;
	sf::Vector2f mVel;
	sf::Vector2f mPos;
	sf::Vector2f mHome;
	sf::Vector2f mWaypoint;
	float mFatalityRate;
	float mInfectionDur;
	const uint32_t mStay = Conf::STAY;

public:
	static int& sGetCount();
	sf::Vector2f getPos(){return mPos;}
	void setStatus(enum Status);
	void setFatalityRate(float);
	auto getStatus(){return mStatus;}
	void setWaypoint(sf::Vector2f && );
	Human();
	~Human();
	void mRenderHuman(sf::RenderWindow&);
	void mMove(float);
};

