#include "../inc/Curves.hpp"
#include <cmath>

namespace Curve {

    Point3D Circle::getPoint(double t) const noexcept {
        return { center.x + radius * cos(t), 
            center.y + radius * sin(t),
            center.z };
    }

    Vector3D Circle::getDerivative(double t) const noexcept {
        return { -radius * sin(t),
            radius * cos(t),
            0.0 };
    }

    void Circle::printInfo() const noexcept {
        std::cout << "Info: "
        << "x: " << center.x << ' '
        << "y: " << center.y << ' '
        << "z: " << center.z << ' '
        << "radius: " << radius << '\n';
    }

    Point3D Ellipse::getPoint(double t) const noexcept {
        return { center.x + radiusX * cos(t), 
            center.y + radiusY * sin(t),
            center.z };
    }

    Vector3D Ellipse::getDerivative(double t) const noexcept {
        return { -radiusX * sin(t),
            radiusY * cos(t),
            0.0 };
    }

    void Ellipse::printInfo() const noexcept {
        std::cout << "Info: "
        << "x: " << center.x << ' '
        << "y: " << center.y << ' '
        << "z: " << center.z << ' '
        << "radius X: " << radiusX << ' '
        << "radius Y: " << radiusY << '\n';
    }

    Point3D Helix::getPoint(double t) const noexcept {
        return { center.x + radius * cos(t), 
            center.y + radius * sin(t),
            center.z + step * t};
    }

    Vector3D Helix::getDerivative(double t) const noexcept {
        return { -radius * sin(t),
            radius * cos(t),
            step };
    }

    void Helix::printInfo() const noexcept {
        std::cout << "Info: "
        << "x: " << center.x << ' '
        << "y: " << center.y << ' '
        << "z: " << center.z << ' '
        << "radius: " << radius << ' '
        << "step: " << step << '\n';
    }

} // namespace Curve