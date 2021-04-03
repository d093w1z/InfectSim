#include "Population.hpp"

Population::Population()
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

Population::~Population()
{
	for(auto h: humans)
	{
		delete h;
	}
}

void Population::renderPopulation(sf::RenderWindow & mWindow)
{
	for(auto it: humans)
	{
		it->mRenderHuman(mWindow);
	}
}

void Population::movePopulation()
{
	sf::Vector2i v(0,0);
	for(auto it: humans)
	{
		it->mMove(v);
	}
}

void Population::stepInfection()
{}