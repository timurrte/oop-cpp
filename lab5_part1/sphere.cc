#include "include/figure.hpp"
#include "include/sphere.hpp"
#include <print>
#include <math.h>

Sphere::Sphere(double radius): Figure((4.0/3.0) * std::numbers::pi * std::pow(radius, 3)) {
    this->radius = radius;
    this->calculate_area();
}

void Sphere::set_r(double radius) {
    this->radius = radius;
    this->calculate_area();
    this->set_v((4.0/3.0) * std::numbers::pi * std::pow(radius, 3));
}

double Sphere::get_r() {
    return this->radius;
}

void Sphere::calculate_area() {
    this->area = 4 * std::numbers::pi * std::pow(this->radius, 2);
}

void Sphere::print_info() {
    std::print("Сфера:\nradius = {}; area = {}; volume = {}\n", this->radius, this->area, this->get_v());
}