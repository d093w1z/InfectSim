#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

#include "Human.hpp"
#include "conf.hpp"
#include "Population.hpp"

class simObj{
	sf::RenderWindow mWindow;
	Population mPop;

public:
	simObj();
	~simObj();
	void run();
	void handleEvents();
	void update();
	void render();
};
