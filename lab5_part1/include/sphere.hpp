#ifndef SPHERE_H
#define SPHERE_H

class Sphere: public Figure {
    private:
        double radius;
        double area;

    public:
        Sphere(double radius);

        void set_r(double radius);
        double get_r();

        void calculate_area();
        double get_area();
        void print_info();
};

#endif