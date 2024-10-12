#include "includes/libs.hpp"
#define DEFAULT_VECTOR_SIZE 10

// Default constructor
CDoubleVector::CDoubleVector() {
    Init(DEFAULT_VECTOR_SIZE);
}

// Constructor with size
CDoubleVector::CDoubleVector(int size) {
    Init(size);
}

// Init method
void CDoubleVector::Init(int size) {
    m_size = size;
    m_pData = new double[m_size];
    for (int i = 0; i < m_size; i++) m_pData[i] = 0;
}

// Copy constructor
CDoubleVector::CDoubleVector(const CDoubleVector& data) {
    m_size = data.getSize();
    m_pData = new double[m_size];
    for (int i = 0; i < m_size; i++) m_pData[i] = data.get(i);
}

// Destructor
CDoubleVector::~CDoubleVector() { clear(); }

// Get vector size
int CDoubleVector::getSize() const { 
    return m_size;
}

// Clear vector
void CDoubleVector::clear() {
    m_size = 0;
    delete [] m_pData;
    m_pData = NULL;
}

// Get value from vector by index
double CDoubleVector::get(int index) const {
    return m_pData[index];
}

// Set value by index
void CDoubleVector::set(int index, double v) {
    if ((m_size>0) && (index<m_size)) m_pData[index] = v;
}

// Get average value
double CDoubleVector::getAvgValue() const {
    double sum = 0;
    for (int i=0; i < m_size; i++) sum += m_pData[i];
    return sum/(double)(m_size);
}

double CDoubleVector::getMax() const {
    double max = m_pData[0];
    for (int i = 0; i < m_size; i++) {
        if (m_pData[i] > max) {
            max = m_pData[i];
        }
    }
    return max;
}

double CDoubleVector::getMin() const {
    double min = m_pData[0];
    for (int i = 0; i < m_size; i++) {
        if (m_pData[i] > min) {
            min = m_pData[i];
        }
    }
    return min;
}

double CDoubleVector::calculate() {
    double sum = 0;
    for (int i = 1; i < 5; i++) {
        double factorial = 1;
        for (int j = 1; j < i; j++) {
            factorial *= j;
        }
        sum += ((m_pData[i] * m_pData[i]) * factorial + m_pData[i])/((m_pData[i]+1)*factorial);
    }
    return sum;
}

double CDoubleVector::calculate(string fileName) {
    double res = this->calculate();
    this->saveResult(res, fileName);
    return res;
}

void CDoubleVector::saveData(string fileName) {
    ofstream fout(fileName);
    if (fout.is_open()) {
        for (int i = 0; i < m_size; i++) {
            fout << m_pData[i] << std::endl;
        }
        fout.close();
    } else {
        std::cout << "There was an error opening file" << std::endl;
    }
}

void CDoubleVector::loadData(string fileName) {
    ifstream fin(fileName);
    if (fin.is_open()) {
        delete[] m_pData;
        m_size = 0;

        double value;
        // Read from file to vector
        while (fin >> value) {
            m_pData[m_size] = value;
            m_size++;
        }     
        fin.close();
    } else {
        std::cout << "There was an error opening the file" << std::endl;
    }
}

void CDoubleVector::saveResult(double data, string fileName) {
    ofstream fout(fileName);

    if (fout.is_open()) {
        fout << data;
        fout.close();
    } else {
        std::cout << "There was an error opening file" << std::endl;
    }
}