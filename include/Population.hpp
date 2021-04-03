/*
* TODO: Implement Population model;
* TODO: design and implement graphing feature;
*/
#include "Human.hpp"
#include "conf.hpp"
#include "MobilityModel.hpp"
#include "utils.hpp"
#include <vector>
class Population {
  std::vector<Human *> humans;
  std::vector<int> infection_history = std::vector<int>(Conf::SIM_HOURS, 0);

public:
  Population();
  ~Population();
  void renderPopulation(sf::RenderWindow &pWindow);
  void movePopulation(float);
  void stepInfection();
};