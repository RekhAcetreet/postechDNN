#pragma once

#include "polygon.h"
#include <tuple>

struct edge
{
	Point p1;
	Point p2;
};

class Eps_graph {

private:

public: // variables
	double eps;
	int row_num, col_num; // (# of points in the eps_graph) = (row_num) * (col_num) // index�� 0���� n-1����
	double x_min; double x_max;
	double y_min; double y_max;
	vector<Grid_Point> grid;
	vector<edge> edges;

	vector <Free_Point> free_points; // �ʱ�ȭ�� �� �̹� anchor�� ��Ű�Ƿ�, add_freept������ anchor��Ű�� �κ��� ���Եž� ��.
	vector <Polygon> polygons;

	vector<tuple<int, int>> dist_coll;	// distance collection for Dijkstra's
	vector<bool> visited;
	vector<int> closest; // gridpt indices in nondecreasing order of distance

public:	// functions
	Eps_graph(vector<Point>, vector<Free_Point>, vector<Polygon>); // lexicographic order�� ������ �� binary search�� insertion/deletion ������ �ͱ����� ���� ��(arbitrary order)
	void make_grid(vector<Point>);
	Grid_Point get_gridpt(indices);

	int ind2num(indices);
	indices num2ind(int);

	bool is_edge(indices, indices);	// checks if two adjacent grid points are adjacent to each other
	void add_edge(indices, indices, double); // �̾߱��ϴ� ��� edge�� grid edge�� ����
	void delete_edge(indices, indices);
	void update_grid(indices, indices);

	void add_freept(Free_Point);
	void delete_freept(Free_Point);
	void delete_freept(int);

	void anchor(Free_Point);	// �߰��� ������ ����, ���� ������
	Grid_Point query_anchor(Free_Point);
	
	void add_pol(Polygon);	// adds a polygon in the epsilon graph
	void delete_pol(int);
	indices* eff_region(Polygon); // effective region of the given polygon. In other words, the rectangular range for checking grid edges again

	void dijkstra(Grid_Point);
	vector<Free_Point> kNN(Free_Point, int); // kNN point query

	void print_grid();
	void print_edges();
	void print_dist();
	void print_kNN(Free_Point, int);

	Eps_graph();
};

/*
	int get_row_num();
	int get_col_num();
	std::vector<edge> get_edges();
*/

/*
	Eps_graph(int* size, double eps);
	void adj_edges(Point);	// for a given grid point, checks if it is adjacent to the point right on the left/on the right/above/below
	std::vector<std::vector<std::tuple<int, long double>>> get_adj_list();

	vector<gridpt> get_grid_mat();
	std::vector<std::vector<std::tuple<int, long double>>> adj_list; // adjacency list
	std::vector<std::tuple<bool, bool, bool>> grid_mat; // adjacency matrix // ������, �Ʒ�, �����ʾƷ�
*/

// int pol_num; // # of polygons