#ifndef CDOUBLE_VECTOR
#define CDOUBLE_VECTOR

#ifndef LIBS
#define LIBS
#include "libs.hpp"
#endif

using namespace std;
class CDoubleVector
{
    private:
        double* m_pData;
        int m_size;

    public:
        CDoubleVector();
        CDoubleVector(int size);
        CDoubleVector(const CDoubleVector& data);
        ~CDoubleVector();

        void Init(int size);
        
        int getSize() const;
        void clear();
        double get(int index) const;
        void set(int index, double v);
        double getAvgValue() const;

        double getMax() const;
        double getMin() const;


        double calculate();
        double calculate(string fileName);

        void saveData(string fileName);
        void loadData(string fileName);

        void saveResult(double data, string fileName);
};
#endif