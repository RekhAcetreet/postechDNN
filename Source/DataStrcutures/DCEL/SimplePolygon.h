#pragma once
#include <vector>
#include "Edge.h"

class SimplePolygon {
private:
	std::vector<Edge*>* edges;
	bool checkSimple(std::vector<Edge*>*);
public:
	SimplePolygon();
	SimplePolygon(std::vector<Edge*>*);
};