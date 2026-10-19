#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "shape.h"

class Triangle : public Shape
{
private:
    double a, b, c;
public:
    Triangle(double x, double y, double z);
    bool isLegal();
    
    double getPerimeter();
    double getArea();
};

#endif
