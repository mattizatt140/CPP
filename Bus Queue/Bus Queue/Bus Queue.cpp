// Bus Queue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "busStop.h"
#include <iostream>
#include <queue>

int main()
{

	busStop Bstop;
	int busArrivalTime;

	Bstop.personArrives(1415);
	Bstop.personArrives(1419);
	Bstop.personArrives(1421);
	Bstop.personArrives(1422);
	Bstop.personArrives(1427);

	busArrivalTime = 1430;
	std::cout << "Bus arrived at " << busArrivalTime << std::endl;
	Bstop.boardBus(busArrivalTime, 2);

	busArrivalTime = 1440;
	std::cout << "Bus arrived at" << busArrivalTime << std::endl;
	Bstop.boardBus(busArrivalTime, 7);
	
}

