// Foundations of Data Structures Module 1 GPA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

class Point {
public:
	int x, y;
};

class LineSeg {
public:
	Point p1, p2;
};

bool onSegment(Point p, Point q, Point r)
{
	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
		q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
		return true;

	return false;
}

int orientation(Point p, Point q, Point r)
{
	int val = (q.y - p.y) * (r.x - q.x) -
		(q.x - p.x) * (r.y - q.y);

	if (val == 0) return 0;  // colinear

	return (val > 0) ? 1 : 2; // clock or counterclock wise
}

bool SegIntersect(class LineSeg l1, class LineSeg l2) {

		int o1 = orientation(l1.p1, l1.p2, l2.p1);
		int o2 = orientation(l1.p1, l1.p2, l2.p2);
		int o3 = orientation(l2.p1, l2.p2, l1.p1);
		int o4 = orientation(l2.p1, l2.p2, l1.p2);
		
		if (o1 != o2 && o3 != o4)
			return true;

		if (o1 == 0 && onSegment(l1.p1, l2.p1, l1.p2)) return true;

		if (o2 == 0 && onSegment(l1.p1, l2.p2, l1.p2)) return true;

		if (o3 == 0 && onSegment(l2.p1, l1.p1, l2.p2)) return true;

		if (o4 == 0 && onSegment(l2.p1, l1.p2, l2.p2)) return true;

		return false; 
}

int main()
{
	struct Point p1 = { 1, 1 }, q1 = { 10, 1 };
	struct Point p2 = { 1, 2 }, q2 = { 10, 2 };

	LineSeg line1, line2;
	line1.p1 = p1;
	line1.p2 = q1;
	line2.p1 = p2;
	line2.p2 = q2;

	SegIntersect(line1, line2) ? cout << "Yes\n" : cout << "No\n";

	p1 = { 10, 0 }, q1 = { 0, 10 };
	p2 = { 0, 0 }, q2 = { 10, 10 };
	line1.p1 = p1;
	line1.p2 = q1;
	line2.p1 = p2;
	line2.p2 = q2;
	SegIntersect(line1, line2) ? cout << "Yes\n" : cout << "No\n";

	p1 = { -5, -5 }, q1 = { 0, 0 };
	p2 = { 1, 1 }, q2 = { 10, 10 };
	line1.p1 = p1;
	line1.p2 = q1;
	line2.p1 = p2;
	line2.p2 = q2;
	SegIntersect(line1, line2) ? cout << "Yes\n" : cout << "No\n";

	return 0;
}