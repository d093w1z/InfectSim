#include "simObj.hpp"

#include <SFML/Graphics.hpp>

#include "conf.hpp"

simObj::simObj()
: mWindow(sf::VideoMode(Conf::MAX_WIDTH, Conf::MAX_HEIGHT), "InfectSim")
, mPop()
{
if (!font.loadFromFile("res/arial.ttf"))
    std::cout << "Failed to load Font\n";


text.setFont(font);
text.setCharacterSize(10);
// text.setColor(sf::Color::Black);
text.setStyle(sf::Text::Regular);
text.setString("");

text.setPosition(30.f,30.f);
}

simObj::~simObj(){}

void simObj::run()
{
	mWindow.setFramerateLimit(100);
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / Conf::FPS);
	int simHours = Conf::SIM_HOURS;
	while(mWindow.isOpen())
	{
		handleEvents();
		while (timeSinceLastUpdate > timePerFrame )
		{
			update(timePerFrame.asSeconds());
			timeSinceLastUpdate -= timePerFrame;
			simHours-=timePerFrame.asSeconds();
			if(simHours<=0)
			{
				break;
			}
		}
		render();
		timeSinceLastUpdate += clock.restart();

	}
}

void simObj::update(float timePerFrame)
{
	mPop.movePopulation(timePerFrame);
	mPop.stepInfection();
}

void simObj::render()
{
	mWindow.clear();
	mPop.renderPopulation(mWindow);
	mWindow.draw(text);
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
				if(event.key.code == sf::Keyboard::P){}
				else if(event.key.code == sf::Keyboard::Escape)
				{
					
				}
				break;
		}
	}
}