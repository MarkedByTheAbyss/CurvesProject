#include <iomanip>
#include <iostream>
#include <numbers>
#include <stdexcept>

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
inline void operator<<(std::ostream& os, Vector3D v) 
{
    os << std::fixed << std::setprecision(4) << v.x << ' ' << v.y << ' ' << v.z << '\n';
}

struct DoubleWrapper {
    DoubleWrapper(double num) : value(num) { if (num <= 0.0) throw std::invalid_argument("Value cannot be negative"); }
    operator double() { return value; };
    operator double() const { return value; };
    double value;
};
constexpr DoubleWrapper operator ""_pi(unsigned long long num) {
    return DoubleWrapper(num * std::numbers::pi);
};

} //namespace Curve