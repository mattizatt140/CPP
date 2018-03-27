#include "stdafx.h"
#include <queue>
#include "busStop.h"
#include <iostream>

int busStop::id = 0;

void busStop::personArrives(int time) {
	personInfo person;
	person.personID = ++id;
	person.arrivalTime = time;
	busQueue.push(person);
	std::cout << "Person: " << busQueue.back().personID;
	std::cout << ", " << busQueue.back().arrivalTime << std::endl;
}

void busStop::boardBus(int busArrivalTime, int availableSeats) {
	int i, count = 0, waitingTime, personArrivalTime = 0;

	for (i = 1; i <= availableSeats; i++) {
		if (!busQueue.empty()) {
			
			personArrivalTime = busQueue.front().arrivalTime;

			std::cout << "\t" << count << " people boarded the bus" << std::endl;
			if (!busQueue.empty()) {
				std::cout << "Next person in the queue: " << busQueue.front().personID << std::endl;
				if (busArrivalTime < personArrivalTime) {
					waitingTime = 0;
				}
				else {
					waitingTime = busArrivalTime - personArrivalTime;
				}
				std::cout << "\tWaiting time of " << busQueue.front().personID;
				std::cout << ": " << waitingTime << std::endl;
				count++;
				busQueue.pop();
			}
			else {
				std::cout << "Nobody waiting in the bus queue" << std::endl;
			}
		}
	}
}