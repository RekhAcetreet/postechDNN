#pragma once

#include <vector>
#include <functional>
#include <queue>
#include <iostream>

using namespace std;

struct indices	// �̰� ����, right�� lower�� �״�� �δ� �� ���� ����.
{
	int row;
	int column;
};

struct incid_pts {
	bool right;		// to represent edges
	bool lower;
	bool left;
	bool upper;
};

class Point {
public:	// variables
	double x, y;	// x- and y- coordinates

public:	// functions
	Point();
	Point(double, double);
	bool operator==(const Point& other) const {	// �����ε� ����� �Ƴ�?
		return !(*this == other);
	}
	void print();
};

class Free_Point : public Point {
	// ���� Point���� �� �߰��� �� ������, gridpoint���� Ȯ���� ������ ����. ���߿� NN �߰��� ���� �ְ�.
public:
	double dist; // distance to the nearest gridpoint
	// Grid_Point host;

public:
	Free_Point();
	Free_Point(double, double);
};

struct cmp {
	bool operator()(Free_Point fp1, Free_Point fp2) {
		return fp1.dist < fp2.dist;
	}
};

class Grid_Point : public Point {
public:
	priority_queue <Free_Point, vector<Free_Point>, cmp> pq;
	indices ind;	// its location on the grid
	// vector<Free_Point> acd_pts;	// free points anchored to it
	incid_pts ip;
	int num;


public:
	Grid_Point();
	Grid_Point(int, int, double, double, double, int);
};

/*
	long double getx();
	long double gety();
	int get_row();
	int get_col();
*/