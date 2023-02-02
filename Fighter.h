#ifndef FIGHTER_H
#define FIGHTER_H
#include "Entity.h"
#include <string>
using namespace std;
/*
    This class represents Fighter overrides move and battle inherited from abstract class Entity
    by Matthew Proctor
*/
class Fighter : public Entity
{
  public:
    Fighter(char avatar, int health, int strength, int armour, Point location, bool alive);
    void move();
	int getStrength();
    int battle(Entity*);

};
#endif
