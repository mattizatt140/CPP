#pragma once
class CylinderA {
public:
	const double PI{ 3.1415926535 };
	double r;
	double h;

	double OuterArea(double r, double h) {
		double area = 2 * PI * r * h;
		return area;
	}

	double TopArea(double r, double h) {
		double area = PI * (r * r);
		return area;
	}

	double TotalArea(double out, double top) {// accepts results of previous two functions
		double area = out + (2 * top);
		return area;
	}
};