#include <iostream>
using namespace std;
#include "Dragon.h"
#include "Point.h"
Dragon::Dragon(char avatar, int health, int strength, int armour, Point location, bool alive, int direction) : Entity(avatar, health, strength, armour, location, alive) {
    this->direction = direction;
}

Dragon::~Dragon()
{
}


/* Dragon's nextMove overrides the pure virtual function inherited from Entity class
   this next move is calculated moving one horizontal position to the right, with a vertical position randomly
   generated between the same vertical position, one position up, or one position down.*/
void Dragon::move()
{   
    if (this->location.getX() == 1) {
        direction = 1;
    }
    if (this->location.getX() == 3) {
        direction = -1;
    }
    this->location.setX(this->location.getX() + direction);
}

int Dragon::battle(Entity*){
    cout << "THIS SHOULD NEVER PRINT" << endl;
    return 0;
}
