#include <iostream>
#include "Graph.hpp"
#include "Vector2.hpp"

int main()
{
	Vector2 point1(1.0f, 2.0f);
	Vector2 point2(3.0f, 4.0f);
	Vector2 point3(5.0f, 6.0f);

	Graph graph;
	graph.addPoint(point1);
	graph.addPoint(point2);
	graph.addPoint(point3);
	graph.drawGraph();

	Vector2 point4(1.0f, 1.0f);

	Graph graph2;
	graph2.addPoint(point1);
	graph2.drawGraph();

	// test empty graph
	Graph graph3;
	graph3.drawGraph();

	Graph graph4;
	Vector2 point5(30.0f, 0.0f);
	graph4.addPoint(point5);
	graph4.drawGraph();

	Graph graph5;
	Vector2 point6(1.0f, 0.0f);
	graph5.addPoint(point6);
	graph5.drawGraph();

	// test point in y axis
	Graph graph6;
	Vector2 point7(0.0f, 1.0f);
	graph6.addPoint(point7);
	graph6.drawGraph();

	// text point in origin
	Graph graph7;
	Vector2 point8(0.0f, 0.0f);
	graph7.addPoint(point8);
	graph7.drawGraph();

	// test importPointsFromFilename
	Graph graph8;
	graph8.importPointsFromFilename("in.txt");
	graph8.drawGraph();

	return 0;
}