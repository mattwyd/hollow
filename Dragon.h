#ifndef DRAGON_H
#define DRAGON_H
#include "Entity.h"
#include "Point.h"
#include <string>
#include "Fighter.h"
using namespace std;
/*
  This class is represents a Dragon, overrides the virtual move function and uses memeber direction to pace back and forth infront of the cave
  by: Matthew Proctor
*/

class Dragon : public Entity
{
public:
    Dragon(char avatar, int health, int strength, int armour, Point location, bool alive, int direction);
    ~Dragon();
    void move();
    int battle(Entity*);
private:
    int direction;
};
#endif
