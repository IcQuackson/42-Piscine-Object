
#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <fstream>
#include "Vector2.hpp"

class Vector2;

class Graph
{

private:
	std::vector<Vector2> points;

public:
	Graph();
	void addPoint(Vector2 point);
	void drawGraph() const;
	void importPointsFromFilename(std::string filename);
};