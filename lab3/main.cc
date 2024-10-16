#include "includes/libs.hpp"

#define MAX 11
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

    cout << "Average value: " << vector->getAvgValue() << endl;

    cout << "Calculation: " << vector->calculate() << endl;

    delete vector;

    return 0;
}