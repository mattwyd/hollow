#ifndef POINT_H
#define POINT_H

using namespace std;
/*
    This class represents a point with values x and y a
    by Matthew Proctor
*/

class Point
{
  public:
    Point(int a, int b);
    Point();
    ~Point();
    void setX(int x);
    void setY(int y);
    int getX();
    int getY();
  private:
    int x;
    int y;
};
#endif
