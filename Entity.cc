#include <iostream>
#include "Entity.h"
using namespace std;
Entity::Entity(char avatar, int health, int strength, int armour, Point &location, bool alive)
{
  this->avatar = avatar;
  this->health = health;
  this->strength = strength;
  this->armour = armour;
  this->location = location;
  this->alive = alive;
}

Entity::~Entity(){}

void Entity::kill()
{
    alive = false;
    avatar = '+';
}

bool Entity::getAlive()
{
    return alive;
}

Point Entity::getLocation()
{
    return this->location;
}

char Entity::getAvatar()
{
    return avatar;
}

int Entity::getStrength()
{
    return strength;
}

void Entity::setLocation(Point newPoint)
{
    location = newPoint;
}
