#include "simObj.hpp"
#include <SFML/Graphics.hpp>

#include "conf.hpp"

simObj::simObj()
: mWindow(sf::VideoMode(MAX_WIDTH, MAX_HEIGHT), "basicGame beta 0.1")
{
	
	humans.reserve(MAX_POP);
	for(int i = 0; i< MAX_POP;i++)
	{
		Human h;
		humans.push_back(h);
	}
}

void simObj::run()
{
	while(mWindow.isOpen())
	{
		handleEvents();
		update();
		render();
	}
}

void simObj::update()
{
	for(auto it: humans)
	{
		it.move();
	}
}

void simObj::render()
{
	mWindow.clear();
	mWindow.display();
}

void simObj::handleEvents()
{
	sf::Event event;
	while(mWindow.pollEvent(event))
	{
		switch(event.type){
			case sf::Event::Closed:
				mWindow.close();
				break;
		}
	}
}