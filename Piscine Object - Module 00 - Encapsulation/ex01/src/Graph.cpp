
#include "Graph.hpp"


Graph::Graph()
{
}

void Graph::addPoint(Vector2 point)
{
	if (point.getX() < 0 || point.getY() < 0)
	{
		std::cerr << "Error: point coordinates must be positive" << std::endl;
		return;
	}
	this->points.push_back(point);
}

void Graph::importPointsFromFilename(std::string filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file " << filename << std::endl;
		return;
	}

	std::string line;
	while (std::getline(file, line))
	{
		if (line.empty())
		{
			continue;
		}
		std::istringstream iss(line);
		float x, y;
		// line format should be "x y"
		if (!(iss >> x >> y))
		{
			std::cerr << "Error: invalid line format" << std::endl;
			return;
		}
		this->addPoint(Vector2(x, y));
	}
	if (this->points.empty())
	{
		std::cout << "No points found in file" << std::endl;
	}
	else
	{
		std::cout << "Points imported from file " << filename << std::endl;
	}
}

void Graph::drawGraph() const {

	// print points
	for (size_t i = 0; i < points.size(); i++) {
		std::cout << "Point " << i << ": " << points[i] << std::endl;
	}
	std::cout << std::endl;

	int xAxisLength = 0;
	int yAxisLength = 0;

	for (size_t i = 0; i < points.size(); i++) {
		xAxisLength = std::max(xAxisLength, static_cast<int>(points[i].getX()));
		yAxisLength = std::max(yAxisLength, static_cast<int>(points[i].getY()));
	}

	int y = yAxisLength;
	while (y >= 0) {
		std::cout << y;

		for (int x = 0; x <= xAxisLength; x++)
		{
			// If there is a point at this position
			bool pointFound = false;
			for (size_t i = 0; i < points.size(); i++) {
				if (static_cast<int>(points[i].getX()) == x
					&& static_cast<int>(points[i].getY()) == y) {
					std::cout << " X ";
					pointFound = true;
					break;
				}
			}
			if (pointFound) {
				continue;
			}
			else if (x == 0 && y == 0)
			{
				std::cout << " .";
			}
			else if (x == 0)
			{
				std::cout << " |";
			}
			else if (y == 0)
			{
				std::cout << "___";
			}
			else
			{
				std::cout << "   ";
			}
		}
		std::cout << std::endl;
		y--;
	}
	// Draw x axis numbers
	int x = 0;
	while (x <= xAxisLength) {
		std::cout << " " << x << " ";
		x++;
	}
	std::cout << std::endl;
	std::cout << std::endl;
}