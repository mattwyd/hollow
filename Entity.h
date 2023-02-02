#ifndef ENTITY_H
#define ENTITY_H
#include "Point.h"
using namespace std;
/*
    ENTITY class is abstract and stores the generic information about a ENTITY as well as creating abstract classes battle and move to be overrided in
    entity's children.
    by: Matthew Proctor
*/
class Entity {
  public:
    Entity(char avatar, int health, int strength, int armour, Point &location, bool alive);
    ~Entity();
    virtual void move() = 0;
    void kill();
    bool getAlive();
    Point getLocation();
    char getAvatar();
    virtual int battle(Entity*) = 0;
    int getStrength();
    void setLocation(Point);
  protected:
    char avatar;
    int health;
    int strength;
    int armour;
    Point location;
    bool alive;
};

#endif
