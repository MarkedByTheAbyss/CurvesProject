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

    Circle(DoubleWrapper rad) : radius(rad) { };

    Point3D getPoint(double t) const noexcept override;
    Vector3D getDerivative(double t) const noexcept override;
    void printInfo () const noexcept override;
    
    double getRadius() const noexcept;

private:
    DoubleWrapper radius;

};

class Ellipse : public ICurve {
public: 

    Ellipse(DoubleWrapper radX, DoubleWrapper radY) : radiusX(radX), radiusY(radY) { };

    Point3D getPoint(double t) const noexcept override;
    Vector3D getDerivative(double t) const noexcept override;
    void printInfo () const noexcept override;

private: 
    DoubleWrapper radiusX;
    DoubleWrapper radiusY;

};

class Helix : public ICurve {
public:

    Helix(DoubleWrapper rad, double step) : radius(rad), step(step) { };

    Point3D getPoint(double t) const noexcept override;
    Vector3D getDerivative(double t) const noexcept override;
    void printInfo () const noexcept override;

private:
    DoubleWrapper radius;
    double step;

};

} // namespace Curve