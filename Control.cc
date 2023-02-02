#include <iostream>
#include <iomanip>
using namespace std;
#include "Entity.h"
#include "Control.h"
#include "Hero.h"
#include "random.h"
#include "Fighter.h"
#include "Dragon.h"
Control::Control(){}
Control::~Control(){}

void Control::launch()
{
    init();
    //game loop
    while (players.getWon() == 0) {
        players.checkWin();
        int temp = random(10);
        if (temp < 6) {
            if (temp == 0 || temp == 1) {
                //dorc
                Fighter* d = new Fighter('d', 5, 6 + random(3), 1, Point(random(5), 25), true);
                players.add(d);
            }
            else if (temp == 2 || temp == 3) {
                //borc
                Fighter* b = new Fighter('b', 5, 8 + random(4), 1, Point(random(5), 25), true);
                players.add(b);
            }
            else if (temp == 4 || temp == 5) {
                //porc
                Fighter* p = new Fighter('p', 5, 4 + random(2), 1, Point(random(5), 25), true);
                players.add(p);
            }
        }
        players.update();
        players.collide();
        view.update(players);
        view.print();
        players.checkWin();
    }
    if (players.getWon() == 1) { cout << "the emerald has been claimed!!" << endl; }
    if (players.getWon() == 2) { cout << "all heros have died..." << endl; }
}

void Control::init()
{
    //spawn entities
    Hero* h = new Hero('H', 15, 5, 1, Point(2, 0), true);
    Hero* t = new Hero('T', 15, 3, 3, Point(1, 0), true);
    Dragon* d = new Dragon('D', 15, 999, 1, Point(2, 24), true, 1);
 
    players.add(h);
    players.add(t);
    players.add(d);
    view.update(players);
    view.print();

}


