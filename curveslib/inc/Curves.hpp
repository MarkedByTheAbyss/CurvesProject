#pragma once

#include "Structs.hxx"

namespace Curve {

struct ICurve {
    virtual Point3D getPoint(double) const = 0;
    virtual Vector3D getDerivative (double) const = 0;
    virtual void printInfo () const = 0;

    virtual ~ICurve() = default;
};

class Circle : public ICurve {
public:

    Circle(Point3D point, DoubleWrapper rad) : radius(rad), center(point) { };

    Point3D getPoint(double t) const noexcept override;
    Vector3D getDerivative(double t) const noexcept override;
    void printInfo () const noexcept override;

public:
    DoubleWrapper radius;
    Point3D center;

};

class Ellipse : public ICurve {
public: 

    Ellipse(Point3D point, DoubleWrapper radX, DoubleWrapper radY) : radiusX(radX), radiusY(radY), center(point) { };

    Point3D getPoint(double t) const noexcept override;
    Vector3D getDerivative(double t) const noexcept override;
    void printInfo () const noexcept override;

public: 
    DoubleWrapper radiusX;
    DoubleWrapper radiusY;
    Point3D center;

};

class Helix : public ICurve {
public:

    Helix(Point3D point, DoubleWrapper rad, double step) : radius(rad), step(step), center(point) { };

    Point3D getPoint(double t) const noexcept override;
    Vector3D getDerivative(double t) const noexcept override;
    void printInfo () const noexcept override;

public:
    DoubleWrapper radius;
    Point3D center;
    double step;

};

} // namespace Curve