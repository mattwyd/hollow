#include <iostream>
using namespace std;
#include <time.h>
#include <cstdlib>
#include "Control.h"

int main()
{
	srand((unsigned)time(NULL));
	Control *c = new Control();
	c->launch();
}
