#include <iostream>
using namespace std;
#include "Hero.h"
#include "Point.h"
#include "random.h"
#include "Fighter.h"
#include "Entity.h"
Hero::Hero(char avatar, int health, int strength, int armour, Point location, bool alive) : Entity(avatar, health, strength, armour, location, alive) {}

int Hero::battle(Entity* f)
{
    health -= (f->getStrength() - this->armour);
    if (health < 1) {
        this->kill();
        return 1;
    }
    else {
        return 0;
    }
}

 
/* Hero's nextMove overrides the pure virtual function inherited from Entity class
   this next move is calculated moving one horizontal position to the right, with a vertical position randomly
   generated between the same vertical position, one position up, or one position down.*/
void Hero::move()
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


    int nextY = this->location.getY() + 1;
    int nextX = this->location.getX() + temp;
    this->location.setX(nextX);
    this->location.setY(nextY);
}
