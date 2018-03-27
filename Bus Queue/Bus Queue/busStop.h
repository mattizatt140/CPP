#pragma once
#include <queue>

struct personInfo {
	int personID;
	int arrivalTime;
};

class busStop {
private:
	static int id;
	std::queue<personInfo> busQueue;
public:
	void personArrives(int time);
	void boardBus(int busArrivalTime, int availableSeats);
};