#ifndef HERO_H
#define HERO_H
#include "Entity.h"
#include "Point.h"


using namespace std;
/*
    This class represents Hero overrides battle overrides move and battle. Battle is used here to calculate hero health after collision
    by Matthew Proctor
*/

class Hero : public Entity
{
  public:
    Hero(char avatar, int health, int strength, int armour, Point location, bool alive);
    int battle(Entity*);
    void move();
};
#endif
