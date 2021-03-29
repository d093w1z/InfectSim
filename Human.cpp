#include "Human.hpp"
#include "utils.hpp"

Human::Human() {
  mStatus = Status::Vulnerable;
  mShape.setPosition(sf::Vector2f(gRandom((int)Conf::MAX_WIDTH),
                                  gRandom((int)Conf::MAX_WIDTH)));
  mID = ++sGetCount();
  mShape.setRadius(3.f);
  mShape.setFillColor(Conf::getColorFromMap(mStatus));
}

Human::~Human() { sGetCount()--; }

int &Human::sGetCount() {
  static int sID = 0;
  return sID;
}

void Human::mRenderHuman(sf::RenderWindow &pWindow) { pWindow.draw(mShape); }

void Human::mMove(sf::Vector2i nPos) {}

void Human::setStatus(enum Status status)
{
	mStatus = status;
}