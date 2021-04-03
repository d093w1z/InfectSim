#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

#include "Human.hpp"
#include "conf.hpp"
#include "Population.hpp"

class simObj{
	sf::RenderWindow mWindow;
	Population mPop;
	sf::Font font;
	sf::Text text;

public:
	simObj();
	~simObj();
	void run();
	void handleEvents();
	void update(float);
	void render();
};
