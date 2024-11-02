#include "include/figure.hpp"
#include "include/parallelepiped.hpp"
#include <print>

Parallelepiped::Parallelepiped(double a, double b, double h): Figure(a*b*h) {
    this->a = a;
    this->b = b;
    this->h = h;
    this->calculate_area();
}

void Parallelepiped::set_a(double a) {
    this->a = a;
    this->calculate_area();
    this->set_v(this->get_area() * this->h);
}
void Parallelepiped::set_b(double b) {
    this->b = b;
    this->calculate_area();
    this->set_v(this->get_area() * this->h);
}
void Parallelepiped::set_h(double h) {
    this->h = h;
    this->set_v(this->get_area() * h);
}

double Parallelepiped::get_a() {
    return this->a;
}
double Parallelepiped::get_b() {
    return this->b;
}
double Parallelepiped::get_h() {
    return this->h;
}
double Parallelepiped::get_area() {
    return this->area;
}

void Parallelepiped::calculate_area() {
    this->area = this->a * this->b;
}
void Parallelepiped::print_info() {
    std::print("Параралеліпіпед:\na = {}; b = {}; h = {}; area = {:.3f}; volume = {:.3f}\n", 
    this->a, this->b, this->h, this->get_area(), this->get_v());
}