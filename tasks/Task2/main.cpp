#include "Shape.h"

#include <iostream>
#include <memory>
#include <vector>

int main() {
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Rectangle>(5.0, 3.0));
    shapes.push_back(std::make_unique<Circle>(4.0));

    for (const auto& shape : shapes) {
        std::cout << "Area: " << shape->getArea() << "\n";
    }

    return 0;
}
