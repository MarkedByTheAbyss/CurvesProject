#include <vector>
#include <algorithm>
#include <random>
#include <memory>

#include "Curves.hpp"

using namespace Curve;

static std::mt19937 rng(std::random_device{}());

double rnd(double min = 0.0, double max = 10.0) {
    std::uniform_real_distribution<double> dist(min, max);
    return dist(rng);
}

int rnd(int min, int max) {
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

void GenerateCurves(std::vector<std::shared_ptr<ICurve>>& curves) {

    curves.push_back(std::make_shared<Circle>(rnd()));
    curves.push_back(std::make_shared<Ellipse>(rnd(), rnd()));
    curves.push_back(std::make_shared<Helix>(rnd(), rnd()));
    
    for (int i = 0; i < 12; ++i) {
        switch (rnd(0, 2)) {
            case 0: 
                curves.push_back(std::make_shared<Circle>(rnd()));
                break;
            case 1:
                curves.push_back(std::make_shared<Ellipse>(rnd(), rnd()));
                break;
            case 2:
                curves.push_back(std::make_shared<Helix>(rnd(), rnd()));
                break;
        }
    }

    std::shuffle(begin(curves), end(curves), rng);
}

int main() {
    std::vector<std::shared_ptr<ICurve>> curves;
    curves.reserve(15);
    GenerateCurves(curves);

    for (auto& e : curves) {
        std::cout << "Point: " << e->getPoint(1_pi / 4);
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