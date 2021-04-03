#include "simObj.hpp"
#include <SFML/Graphics.hpp>

#include "conf.hpp"

simObj::simObj()
: mWindow(sf::VideoMode(Conf::MAX_WIDTH, Conf::MAX_HEIGHT), "basicGame beta 0.1")
, mPop()
{
}

simObj::~simObj(){}

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
	mPop.movePopulation();
	mPop.stepInfection();
}

void simObj::render()
{
	mWindow.clear();
	mPop.renderPopulation(mWindow);
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
			case sf::Event::KeyPressed:
				if(event.key.code == sf::Keyboard::P){
				}
				break;
		}
	}
}