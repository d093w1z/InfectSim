#include "Human.hpp"
#include "utils.hpp"
#include <cmath>
#include <iomanip>
#include <iostream>

bool operator>(sf::Vector2f a, sf::Vector2f b) {
  return sqrt(pow(a.x, 2) + pow(a.y, 2)) > sqrt(pow(b.x, 2) + pow(b.y, 2));
}

sf::Vector2f operator*(float k, sf::Vector2f a) {
  return sf::Vector2f(k * a.x, k * a.y);
}

Human::Human() {
  mStatus = Status::Vulnerable;
  mFatalityRate = Conf::NORMAL_FATALITY_RATE;
  mInfectionDur = Conf::INFECTION_DUR;
  mPos = sf::Vector2f(gRandom((int)Conf::MAX_WIDTH),
                      gRandom((int)Conf::MAX_HEIGHT));
  mVel = sf::Vector2f(0, 0);
  mHome = mPos;
  mWaypoint = sf::Vector2f(-1, -1);
  mID = ++sGetCount();
  mShape.setPosition(mPos);
  mShape.setRadius(3.f);
  mShape.setFillColor(Conf::getColorFromMap(mStatus));
  mWay.setFillColor(sf::Color::Blue);
  mWay.setSize(sf::Vector2f(10, 10));
  mWay.setPosition(mWaypoint);
}

Human::~Human() { sGetCount()--; }

int &Human::sGetCount() {
  static int sID = 0;
  return sID;
}

void Human::mRenderHuman(sf::RenderWindow &pWindow) {
  pWindow.draw(mShape);
  // pWindow.draw(mWay);  
}

void Human::mMove(float timePerFrame) {
  if(mStatus != Status::Dead){
    sf::Vector2f pos2target = mWaypoint - mPos;
    float mag = sqrt(pow(pos2target.x, 2) + pow(pos2target.y, 2));
    mVel.x = (100 * pos2target.x / (mag));
    mVel.y = (100 * pos2target.y / (mag));
    if (pos2target > 0.2 * mVel) {
      mPos += timePerFrame * mVel;

      if (mPos.x < 0) {
        mPos.x += Conf::MAX_WIDTH;
      }
      if (mPos.x > Conf::MAX_WIDTH) {
        mPos.x -= Conf::MAX_WIDTH;
      }
      if (mPos.y < 0) {
        mPos.y += Conf::MAX_HEIGHT;
      }
      if (mPos.y > Conf::MAX_HEIGHT) {
        mPos.y -= Conf::MAX_HEIGHT;
      }
      // std::cout<<mID<<std::fixed<<std::setprecision(2)<<timePerFrame<<"\t"<<(mPos
      // - mWaypoint).x << "\t"<< (mPos - mWaypoint).y<<std::endl;
    } else if(mWaypoint == mHome) {
      setWaypoint(sf::Vector2f(gRandom((int)Conf::MAX_WIDTH),
                               gRandom((int)Conf::MAX_HEIGHT)));
    } else{
      mWaypoint = mHome;
    }

      mWay.setPosition(mWaypoint);

    }
    if(mStatus == Status::Infected){
      if(mInfectionDur <= 0){
        if(gChance(mFatalityRate))
        {  
          setStatus(Status::Dead);
          // std::cout<<mID<<" is Dead."<<"\n";
        }
        else{
          setStatus(Status::Immune);
          // std::cout<<mID<<" is Immune."<<"\n";
        }
      }
      else{
        mInfectionDur -= 60*timePerFrame;
      }
    }

    mShape.setPosition(mPos);
    
}

void Human::setStatus(enum Status status) {
  mStatus = status;
  mShape.setFillColor(Conf::getColorFromMap(mStatus));
}

void Human::setFatalityRate(float rate) { mFatalityRate = rate; }

void Human::setWaypoint(sf::Vector2f &&v) { mWaypoint = v; }
