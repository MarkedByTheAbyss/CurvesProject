#include <iterator>
#include <vector>
#include <algorithm>
#include <random>

#include "Curves.hpp"

using namespace Curve;

double rnd(double min, double max) {
    static std::mt19937 rng(std::random_device{}());
    std::uniform_real_distribution<double> dist(min, max);
    return dist(rng);
}

void GenerateCurves(std::output_iterator<ICurve*> auto iter) {
    for (int i = 0; i < 5; ++i, ++iter) {
        *iter = new Circle({rnd(0.0, 10.0), rnd(0.0, 10.0), rnd(0.0, 10.0)}, 
        rnd(0.0, 10.0));
    }
    for (int i = 0; i < 5; ++i, ++iter) {
        *iter = new Ellipse({rnd(0.0, 10.0), rnd(0.0, 10.0), rnd(0.0, 10.0)}, 
        rnd(0.0, 10.0), rnd(0.0, 10.0));
    }
    for (int i = 0; i < 5; ++i, ++iter) {
        *iter = new Helix({rnd(0.0, 10.0), rnd(0.0, 10.0), rnd(0.0, 10.0)}, 
        rnd(0.0, 10.0), rnd(0.0, 10.0));
    }
}

int main() {
    std::vector<ICurve*> curves;
    curves.reserve(15);
    GenerateCurves(std::back_insert_iterator(curves));

    for (auto& e : curves) {
        std::cout << "Point: " << e->getPoint(1_pi / 2);
        std::cout << "Derivative: " << e->getDerivative(1_pi / 4);
        e->printInfo();
        std::cout << std::endl;
    }

    std::vector<Circle*> circles;
    for (auto& e : curves) { 
        Circle* ptr = dynamic_cast<Circle*>(e);
        if (ptr != nullptr)
            circles.push_back(ptr);
    }
    std::sort(begin(circles), end(circles), [](Circle* lhs, Circle* rhs){
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