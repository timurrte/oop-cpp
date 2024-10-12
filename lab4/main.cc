#ifndef LIBS
#define LIBS
#include "includes/libs.hpp"
#endif
#define MAX 4
#define CLEAR_CIN cin.ignore(255, '\n')

using namespace std;

int main(int argc, char* argv[])
{
	int i=0;
    CDoubleVector* vector = new CDoubleVector(MAX);

    for (i=0; i<MAX; i++) {
        double v = 0;
        cout << "Enter " << i+1 << " element: ";
        cin >> v;
        CLEAR_CIN;
        vector->set(i, v);
    }

    for (i = 0; i<MAX; i++) cout << vector->get(i) << " ";
    cout << endl;

    CDoubleVector test(*vector);
    for (i=0; i<MAX; i++) cout << test.get(i) << " ";
    cout << endl;

    vector->saveData("hello.dat");
    delete vector;

    CDoubleVector* vector2 = new CDoubleVector(MAX);
    vector2->loadData("hello.dat");
    cout << "Average value: " << vector2->getAvgValue() << endl;

    double result = vector2->calculate("result.dat");
    cout << "Calculation: " << result << endl;
    delete vector2;

    return 0;
}