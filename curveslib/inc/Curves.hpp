#include <iomanip>
#include <ostream>

namespace Curve {

struct Point3D {
    double x, y, z;
};
inline void operator<<(std::ostream& os, Point3D p) 
{
    os << std::fixed << std::setprecision(4) << p.x << ' ' << p.y << ' ' << p.z << '\n';
}

struct Vector3D {
    double x, y, z;
};

struct ICurve {
    virtual Point3D getPoint(double) const = 0;
    virtual Vector3D getDerivative (double) const = 0;

    virtual ~ICurve() = default;
};

class Circle : public ICurve {
public:

    Circle(Point3D point, double rad) : radius(rad), center(point) { };

    Point3D getPoint(double t) const noexcept override;
    Vector3D getDerivative(double t) const noexcept override;

private:
    double radius;
    Point3D center;

};

class Ellipse : public ICurve {
public: 

    Ellipse(Point3D point, double radX, double radY) : radiusX(radX), radiusY(radY), center(point) { };

    Point3D getPoint(double t) const noexcept override;
    Vector3D getDerivative(double t) const noexcept override;

private: 
    double radiusX;
    double radiusY;
    Point3D center;

};

class Helix : public ICurve {
public:

    Helix(Point3D point, double rad, double step) : radius(rad), step(step), center(point) { };

    Point3D getPoint(double t) const noexcept override;
    Vector3D getDerivative(double t) const noexcept override;

private:
    double radius;
    double step;
    Point3D center;

};

} // namespace Curve