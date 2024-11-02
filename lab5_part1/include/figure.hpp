#ifndef FIGURE_H
#define FIGURE_H

class Figure {
    private:
        double volume;

    public:
        Figure(double volume);

        void set_v(double v);
        double get_v();
        void print_info();
};

#endif