#include <iostream>
using namespace std;
#include "Fighter.h"
#include "Point.h"
#include "random.h"
Fighter::Fighter(char avatar, int health, int strength, int armour, Point location, bool alive) : Entity(avatar, health, strength, armour, location, alive) {}


/* Fighter's nextMove overrides the pure virtual function inherited from Entity class
   this next move is calculated moving one horizontal position to the right, with a vertical position randomly
   generated between the same vertical position, one position up, or one position down.*/
void Fighter::move()
{
    int temp = 0;
    switch (random(3)) {
    case 0:
        temp = 1;
        break;
    case 1:
        temp = 0;
        break;
    case 2:
        temp = -1;
        break;
    }
  
    this->location.setX(this->location.getX() + temp);
    this->location.setY(this->location.getY() - 1);
}

int Fighter::getStrength() {
    return strength;
}

int Fighter::battle(Entity*)
{
    return 0;
}
