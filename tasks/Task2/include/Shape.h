#ifndef SHAPE_H
#define SHAPE_H

class Shape {
public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
};

class Rectangle : public Shape {
public:
    Rectangle(double width, double height);
    double getArea() const override;

private:
    double width_;
    double height_;
};

class Circle : public Shape {
public:
    explicit Circle(double radius);
    double getArea() const override;

private:
    double radius_;
};

#endif // SHAPE_H
