#ifndef CONTROL_H
#define CONTROL_H

#include "Players.h"
#include "View.h"
/*
    Control class is used controlling program flow
    by: Matthew Proctor
*/

class Control
{
  public:
    Control();
    ~Control();
    void launch();
    void init();
  private:
    View<char> view;
    Players players;
};

#endif
