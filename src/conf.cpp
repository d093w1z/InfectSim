#include "conf.hpp"

const float Conf::FPS = 60.f;

const uint32_t Conf::MAX_HEIGHT = 700;
const uint32_t Conf::MAX_WIDTH = 600;
const uint32_t Conf::STAY = 1;


const uint32_t Conf::MAX_POP = 100;
const uint32_t Conf::SIM_HOURS = 3000;

const uint32_t Conf::INFECTION_DUR = 20*24;
const uint32_t Conf::INITIAL_INFECTIONS = 5;

const float Conf::INFECTION_PROBABILITY = 0.5;
const float Conf::NORMAL_FATALITY_RATE = 0.02;
const float Conf::SATURATION_FATALITY_RATE = 0.06;
const float Conf::SATURATION_THRESHOLD = MAX_POP/5;
const float Conf::INFECTION_PROXIMITY = 5.0;
	

const sf::Color & Conf::getColorFromMap(enum Status status)
{
	// const std::unordered_map<enum Status, sf::Color> * cMap= &ColorMap();
	auto it = ColorMap().find(status);
	return it->second;
}
