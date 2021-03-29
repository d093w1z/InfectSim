#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

#include "Human.hpp"
#include "conf.hpp"

class simObj{
	sf::RenderWindow mWindow;
	std::vector<Human *> humans;
	std::vector<int> infection_history = std::vector<int>( Conf::SIM_HOURS, 0);

public:
	simObj();
	~simObj();
	void run();
	void handleEvents();
	void update();
	void render();
};
