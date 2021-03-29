#include "simObj.hpp"
#include <SFML/Graphics.hpp>

#include "conf.hpp"

simObj::simObj()
: mWindow(sf::VideoMode(Conf::MAX_WIDTH, Conf::MAX_HEIGHT), "basicGame beta 0.1")
{
	infection_history.reserve(Conf::SIM_HOURS);
	humans.reserve(Conf::MAX_POP);
	Human * h;
	for(uint32_t i = 0; i< Conf::MAX_POP;i++)
	{
		h = new Human();
		humans.push_back(h);
	}
	for(uint32_t i = 0; i< Conf::INITIAL_INFECTIONS;i++)
	{
		humans[i]->setStatus(Status::Infected);
	}
}

simObj::~simObj(){
	for(auto h: humans)
	{
		delete h;
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
	sf::Vector2i v(0,0);
	for(auto it: humans)
	{
		it->mMove(v);
	}
}

void simObj::render()
{
	mWindow.clear();
	for(auto it: humans)
	{
		it->mRenderHuman(mWindow);
	}
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
					for(auto it: infection_history)
					{
						std::cout<<it<<std::endl;
					}
				}
				break;
		}
	}
}