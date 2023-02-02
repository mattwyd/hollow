#include <iostream>
#include <iostream>
using namespace std;
#include <list>
#include <iterator>
#include "Players.h"
#include "Point.h"
Players::Players()
{
	won = 0;
	numDead = 0;
}

Players::~Players()
{
}

void Players::update()
{
	list<Entity*>::iterator it;
	for (it = all.begin(); it != all.end(); it++)
	{
		if((*it)->getAlive()){
			(*it)->move();
		}
	}
}
void Players::add(Entity* e) {
	all.push_back(e);
}

void Players::checkWin() {
	if (numDead == 2) {
		won = 2;
	}
	for (it = all.begin(); it != all.end(); it++)
	{
		if (((*it)->getLocation().getX() > 0 && (*it)->getLocation().getX() < 4) && ((*it)->getLocation().getY() == 24) && ((*it)->getAvatar() == 'T' || (*it)->getAvatar() == 'H')) {
			won = 1;
		}
	}
}

int Players::getWon()
{
	return won;
}

list<Entity*> Players::getList() {
	return all;
}

void Players::collide()
{
	list<Entity*>::iterator it;
	list<Entity*>::iterator jit;
	for (it = all.begin(); it != all.end(); it++)
	{
		//checkWin();
		if ((*it)->getAlive()) {
			Point current = (*it)->getLocation();
			//wall collisions
			if (current.getX() < 0)
			{
				current.setX(0);
				(*it)->setLocation(current);
			}
			if (current.getX() >  4)
			{ 
				current.setX(4);
				(*it)->setLocation(current);

			}
			if (current.getY() < 0) {
				current.setY(0);
				(*it)->setLocation(current);

			}
			if (current.getY() > 24)
			{ 
				current.setY(24);
				(*it)->setLocation(current);

			}
		
			//player collisions
			Entity* temp = *it;
			for (jit = all.begin(); jit != all.end(); jit++) {
				if (temp->getLocation().getX() == (*jit)->getLocation().getX() && temp->getLocation().getY() == (*jit)->getLocation().getY()) {
					//if hero v dragon
					if (((temp->getAvatar() == 'H' || temp->getAvatar() == 'T') && (*jit)->getAvatar() == 'D')) {
						if (temp->battle(*jit) == 1) { numDead++; }
					}
					if (temp->getAvatar() == 'D' && ((*jit)->getAvatar() == 'H' || (*jit)->getAvatar() == 'T')) {
						if ((*jit)->battle(temp) == 1) { numDead++; }
					}

					//if hero v fighter
					if ((temp->getAvatar() == 'H' || temp->getAvatar() == 'T') && ((*jit)->getAvatar() == 'p' || (*jit)->getAvatar() == 'd' || (*jit)->getAvatar() == 'b')) {
						if (temp->battle(*jit) == 1) { numDead++; }
					}
					if ((temp->getAvatar() == 'p' || temp->getAvatar() == 'b' || temp->getAvatar() == 'd') && ((*jit)->getAvatar() == 'H' || (*jit)->getAvatar() == 'T')) {
						if ((*jit)->battle(temp) == 1) { numDead++; }
					}

				}				
			}
		}
	}
}
