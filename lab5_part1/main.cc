#include "include/figure.hpp"
#include "include/parallelepiped.hpp"
#include "include/sphere.hpp"
#include <iostream>
#include <print>

int main() {
    Figure fig(3);
    fig.print_info();

    Parallelepiped par(3.1, 5.7, 3.2);
    par.print_info();

    Sphere sph(5.3);
    sph.print_info();
}