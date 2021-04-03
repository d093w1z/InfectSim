#include <cassert>
#include "Population.hpp"

Population::Population()
{
	assert(Conf::MAX_POP > Conf::INITIAL_INFECTIONS);
	infection_history.reserve(Conf::SIM_HOURS);
	humans.reserve(Conf::MAX_POP);
	Human * h;
	for(uint32_t i = 0; i< Conf::MAX_POP;i++)
	{
		h = new Human();
		humans.push_back(h);
		h->setWaypoint(sf::Vector2f(gRandom((int)Conf::MAX_WIDTH),
                                  	gRandom((int)Conf::MAX_WIDTH)));
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

void Population::movePopulation(float timeperframe)
{
	for(auto it: humans)
	{
		it->mMove(timeperframe);
	}
}

void Population::stepInfection()
{
	for(auto it1: humans)
	{
		for(auto it2: humans)
		{
			if(it1->getStatus() == Status::Infected)
			{
				if(it1 != it2)
				{
					if(it2->getStatus() == Status::Vulnerable)
					{
						sf::Vector2f pos2target = it1->getPos() - it2->getPos();
						float mag = sqrt(pow(pos2target.x, 2) + pow(pos2target.y , 2));
						if(mag<=Conf::INFECTION_PROXIMITY)
						{
							if(gChance(Conf::INFECTION_PROBABILITY))
							{
								it2->setStatus(Status::Infected);
							}
						}	
					}
				}
			}
		}
	}
}