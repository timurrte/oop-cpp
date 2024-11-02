#include "include/figure.hpp"
#include <print>

Figure::Figure(double v) {
    this->volume = v;
}

void Figure::set_v(double v) {
    this->volume = v;
}

double Figure::get_v() {
    return this->volume;
}

void Figure::print_info() {
    std::print("Фігура:\nvolume = {}\n", this->volume);
}