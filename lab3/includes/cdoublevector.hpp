#ifndef CDOUBLE_VECTOR
#define CDOUBLE_VECTOR

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
};
#endif