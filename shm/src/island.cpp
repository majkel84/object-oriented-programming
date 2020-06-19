#include "island.hpp"

Coordinates::Coordinates(size_t posX, size_t posY)
    : positionX_(posX), positionY_(posY)
{}

Island::Island(size_t posX, size_t posY)
    : position_(posX, posY)
{}

Coordinates Island::getPosition() {
    return position_;
}