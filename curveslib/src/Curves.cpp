#include "../inc/Curves.hpp"
#include <cmath>

namespace Curve {

    Point3D Circle::getPoint(double t) const noexcept {
        return { radius * cos(t), 
            radius * sin(t),
            0.0 };
    }

    Vector3D Circle::getDerivative(double t) const noexcept {
        return { -radius * sin(t),
            radius * cos(t),
            0.0 };
    }

    void Circle::printInfo() const noexcept {
        std::cout << "Info: "
        << "radius: " << radius << '\n';
    }

    Point3D Ellipse::getPoint(double t) const noexcept {
        return { radiusX * cos(t), 
            radiusY * sin(t),
            0.0 };
    }

    Vector3D Ellipse::getDerivative(double t) const noexcept {
        return { -radiusX * sin(t),
            radiusY * cos(t),
            0.0 };
    }

    void Ellipse::printInfo() const noexcept {
        std::cout << "Info: "
        << "radius X: " << radiusX << ' '
        << "radius Y: " << radiusY << '\n';
    }

    Point3D Helix::getPoint(double t) const noexcept {
        return { radius * cos(t), 
            radius * sin(t),
            step * t / 2_pi };
    }

    Vector3D Helix::getDerivative(double t) const noexcept {
        return { -radius * sin(t),
            radius * cos(t),
            step / 2_pi };
    }

    void Helix::printInfo() const noexcept {
        std::cout << "Info: "
        << "radius: " << radius << ' '
        << "step: " << step << '\n';
    }

} // namespace Curve