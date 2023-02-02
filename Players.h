#ifndef PLAYERS_H
#define PLAYERS_H
using namespace std;
#include <list>
#include "Entity.h"
/*
    This class is the collection class for the Entity's 
    by: Matthew Proctor
*/
class Players
{
  public:
    Players();
    ~Players();
    void update();
    void add(Entity* e);
    void checkWin();
    int getWon();
    list<Entity*> getList();
    void collide();
  protected:
    list<Entity*> all;
    list<Entity*>::iterator it;
    int numDead;
    int won;
};

#endif
