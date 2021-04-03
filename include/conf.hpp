#include <SFML/Graphics.hpp>
#include <unordered_map>
/*
 */
#pragma once

#define VERSION 0.1

enum Status { Vulnerable, Infected, Immune, Dead };

struct Conf {
  const static uint32_t MAX_HEIGHT;
  const static uint32_t MAX_WIDTH;
  const static uint32_t MAX_POP;
  const static uint32_t SIM_HOURS;
  const static uint32_t STAY;
  const static uint32_t INFECTION_DUR;
  const static uint32_t INITIAL_INFECTIONS;
  const static float INFECTION_PROBABILITY;
  const static float NORMAL_FATALITY_RATE;
  const static float SATURATION_FATALITY_RATE;
  const static float SATURATION_THRESHOLD;
  const static float INFECTION_PROXIMITY;
  const static float FPS;

  const static sf::Color &getColorFromMap(enum Status);

private:
  Conf();
  Conf(const Conf &a) = delete;
  Conf &operator=(Conf &) = delete;

  inline const static std::unordered_map<enum Status, sf::Color> ColorMap() {
    const static std::unordered_map<enum Status, sf::Color> ColorMap = {
        {Vulnerable, sf::Color::Yellow},
        {Infected, sf::Color::Red},
        {Immune, sf::Color::Cyan},
        {Dead, sf::Color::White},
    };
    return ColorMap;
  }
};
