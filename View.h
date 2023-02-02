#ifndef VIEW_H
#define VIEW_H
#include <iostream>
#include <string>
#define MAP_HEIGHT 5
#define MAP_WIDTH 25
#include "Players.h"
using namespace std;
/*
	This class represents View represents a 2D array for the gameboard
	by Matthew Proctor
*/
template <class T>
class View
{
  public:
	  View<T>();
	  ~View();
      void update(Players);
      void print();
  private:

	  int rows;
	  int cols;

	  T **map;
};

#endif
template<class T>
View<T>::View()
{
		rows = 5;
		cols = 25;
		map = new T * [MAP_HEIGHT];
		for (int i = 0; i < MAP_HEIGHT; i++) {
			map[i] = new T[MAP_WIDTH];
		}
}

	template<class T>
	View<T>::~View()
{
		for (int i = 0; i < rows; i++)
			delete[] map[i];
		delete[] map;
}
template <class T>
void View<T>::update(Players p)
{
	//traverse the 2D array 
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			map[i][j] = ' ';
		}
	}
	list<Entity*> players = p.getList();
	list<Entity*>::iterator it;
	for (it = players.begin(); it != players.end(); it++)
	{

		Point currentLocation = (*it)->getLocation();
		int xCoodinate = currentLocation.getX();
		int yCoordinate = currentLocation.getY();
		map[xCoodinate][yCoordinate] = (*it)->getAvatar();
	}
}
template <class T>
void View<T>::print()
{
	//write top line
	cout << "|-------------------------|" << endl;

	//write 2D array
	for (int i = 0; i < MAP_HEIGHT; i++) {
		cout << '|';
		for (int j = 0; j < MAP_WIDTH; j++) {
			cout << map[i][j];
		}
		if (i > 0 && i < 4) {
			//drawing cave
			cout << '=';
			if (i == 2) {
				//placing emerald
				cout << " *";
			}
		}
		else {
			cout << '|';
		}
		cout << endl;
	}
	cout << "|-------------------------|" << endl;
}
