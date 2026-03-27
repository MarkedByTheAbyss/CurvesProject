#include <vector>
#include <algorithm>
#include <random>

#include "Curves.hpp"

using namespace Curve;

double rnd(double min = 0.0, double max = 10.0) {
    static std::mt19937 rng(std::random_device{}());
    std::uniform_real_distribution<double> dist(min, max);
    return dist(rng);
}

void GenerateCurves(std::vector<std::shared_ptr<ICurve>>& curves) {
    for (int i = 0; i < 5; ++i) {
        curves.push_back(std::make_shared<Circle>(Point3D{rnd(), rnd(), rnd()}, rnd()));
    }
    for (int i = 0; i < 5; ++i) {
        curves.push_back(std::make_shared<Ellipse>(Point3D{rnd(), rnd(), rnd()}, rnd(), rnd()));
    }
    for (int i = 0; i < 5; ++i) {
        curves.push_back(std::make_shared<Helix>(Point3D{rnd(), rnd(), rnd()}, rnd(), rnd()));
    }
}

int main() {
    std::vector<std::shared_ptr<ICurve>> curves;
    curves.reserve(15);
    GenerateCurves(curves);

    for (auto& e : curves) {
        std::cout << "Point: " << e->getPoint(1_pi / 2);
        std::cout << "Derivative: " << e->getDerivative(1_pi / 4);
        e->printInfo();
        std::cout << std::endl;
    }

    std::vector<std::shared_ptr<Circle>> circles;
    for (auto& e : curves) { 
        if (auto ptr = std::dynamic_pointer_cast<Circle>(e))
            circles.push_back(ptr);
    }
    std::sort(begin(circles), end(circles), [](auto lhs, auto rhs) {
        return lhs->radius < rhs->radius;
    });
    double sum = 0.0;
    std::cout << "Sorted Circle radii: ";
    for (auto& e : circles) {
        sum += e->radius;
        std::cout << e->radius << ' ';
    }
    std::cout << std::endl;
    std::cout << "Radii sum of Circles: " << sum << std::endl;
    std::cout << std::endl;
}