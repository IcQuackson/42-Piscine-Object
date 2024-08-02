#include <assert.h>
#include "shape.hpp"
#include "triangle.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

void testTriangle()
{
    Triangle triangle(3, 4, 5);

    int area = triangle.calculateArea();
    int perimeter = triangle.calculatePerimeter();
    assert(area == 6);
    assert(perimeter == 12);
}

void testRectangle()
{
    Rectangle rectangle(3, 4);
    assert(rectangle.calculateArea() == 12);
    assert(rectangle.calculatePerimeter() == 14);
}

void testCircle()
{
    Circle circle(3);
    int area = circle.calculateArea();
    int perimeter = circle.calculatePerimeter();
    assert(area == 28);
    assert(perimeter == 18);
}

void testLiskovSubstitutionPrinciple()
{
    Shape *shapes[] = {new Triangle(3, 4, 5), new Rectangle(3, 4), new Circle(3)};
    
    int triangleArea = shapes[0]->calculateArea();
    int rectangleArea = shapes[1]->calculateArea();
    int circleArea = shapes[2]->calculateArea();
    int trianglePerimeter = shapes[0]->calculatePerimeter();
    int rectanglePerimeter = shapes[1]->calculatePerimeter();
    int circlePerimeter = shapes[2]->calculatePerimeter();

    assert(triangleArea == 6);
    assert(rectangleArea == 12);
    assert(circleArea == 28);
    assert(trianglePerimeter == 12);
    assert(rectanglePerimeter == 14);
    assert(circlePerimeter == 18);

    delete shapes[0];
    delete shapes[1];
    delete shapes[2];
}

int main()
{
    testTriangle();
    testRectangle();
    testCircle();
    testLiskovSubstitutionPrinciple();
    return 0;
}