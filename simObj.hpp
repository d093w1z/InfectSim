#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

#include "Human.hpp"

class simObj{
	sf::RenderWindow mWindow;
	std::vector<Human> humans;

public:
	simObj();

	void run();
	void handleEvents();
	void update();
	void render();
};