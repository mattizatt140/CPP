#include "stdafx.h"
#include <iostream>
#include <string>
#include "CylinderA.h"
using namespace std;

int main()
{
	string input;
	double r, h, area, area1, area2;

	cout << "Input radius of tank: ";
	cin >> r;
	cout << "Input height of tank: ";
	cin >> h;

	CylinderA *p = new CylinderA;
	area1 = p->OuterArea(r, h);
	area2 = p->TopArea(r, h);
	area = p->TotalArea(r, h);
	
	cout << "The tank's surface area is " << area << " squared centimeters\n";
	cout << "Would you like to convert to squared meters?" << endl << "Yes or no?" << endl;
	cin >> input;

	if (input != "No" && input != "no")
	{
		cout << "The tank's surface area in meters is " << (area / 100) << " meters squared\n";
		system("PAUSE");
	}
	else
	{
		system("PAUSE");
	}
}

