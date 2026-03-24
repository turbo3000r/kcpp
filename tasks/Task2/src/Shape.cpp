#include "Shape.h"

static constexpr double PI = 3.14159265358979323846;

Rectangle::Rectangle(double width, double height)
    : width_(width), height_(height) {}

double Rectangle::getArea() const {
    return width_ * height_;
}

Circle::Circle(double radius)
    : radius_(radius) {}

double Circle::getArea() const {
    return PI * radius_ * radius_;
}
