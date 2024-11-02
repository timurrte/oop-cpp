#ifndef TAX_H
#define TAX_H

class Parallelepiped: public Figure {
    private:
        double a, b;
        double h;
        double area;

    public:
        Parallelepiped(double a, double b, double h);
        void set_a(double);
        void set_b(double);
        void set_h(double);

        double get_a();
        double get_b();
        double get_h();

        void calculate_area();
        double get_area();

        void print_info();
};

#endif