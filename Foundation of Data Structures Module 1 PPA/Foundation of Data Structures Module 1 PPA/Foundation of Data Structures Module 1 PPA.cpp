// Foundation of Data Structures Module 1 PPA.cpp : Defines the entry point for the console application

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

struct vertex {
	float x;
	float y;
};

struct triangle {
	vertex vertices[3];
};

float cal_area(triangle aTriangle) {
	float area;
	//area = std::abs(x0 * (y1 - y2) + x1 * (y2 - y0) + x2 * (y0 - y1)) / 2;
	float a, b, c, s;

	a = sqrt((aTriangle.vertices[0].x - aTriangle.vertices[1].x)*
			 (aTriangle.vertices[0].x - aTriangle.vertices[1].x) +
			 (aTriangle.vertices[0].y - aTriangle.vertices[1].y)*
			 (aTriangle.vertices[0].y - aTriangle.vertices[1].y));
	b = sqrt((aTriangle.vertices[1].x - aTriangle.vertices[2].x)*
		    (aTriangle.vertices[1].x - aTriangle.vertices[2].x) +
		    (aTriangle.vertices[1].y - aTriangle.vertices[2].y)*
		    (aTriangle.vertices[1].y - aTriangle.vertices[2].y));
	c = sqrt((aTriangle.vertices[0].x - aTriangle.vertices[2].x)*
			(aTriangle.vertices[0].x - aTriangle.vertices[2].x) +
			(aTriangle.vertices[0].y - aTriangle.vertices[2].y)*
			(aTriangle.vertices[0].y - aTriangle.vertices[2].y));
	s = (a + b + c) / 2;

	area = sqrt((s*(s - a)*(s - b)*(s - c)));

	return area;

	//Dont write below this line
}