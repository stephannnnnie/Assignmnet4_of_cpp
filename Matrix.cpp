//
// Created by stephannie on 2020/12/5.
//

#include "Matrix.h"
#include <immintrin.h>
#include <iomanip>
Matrix::Matrix() {
    row_num = 1;
    column_num = 1;
    data = new float[1];
}

Matrix::Matrix(int a, int b,float * c) {
    row_num = a;
    column_num = b;
    data = new float [a*b];
    data = c;
}

Matrix::Matrix(int a, int b) {
    row_num = a;
    column_num = b;
    data = new float[a*b];
}

Matrix::Matrix(const Matrix& mat)
{
    row_num = mat.row_num;
    column_num = mat.column_num;
    data = new float[row_num * column_num];
    for (size_t i = 0; i < row_num * column_num; i++)
    {
        data[i] = mat.data[i];
    }
}

Matrix::~Matrix() {
    delete[] data;
    //cout << "destructor called" << endl;
}

Matrix& Matrix::operator=(const Matrix& matrix) {
    if (this == &matrix) {
        return *this;
    }
    delete[] data;
    row_num = matrix.row_num;
    column_num = matrix.column_num;
    for (int i = 0; i < row_num * column_num; ++i) {
        data[i] = matrix.data[i];
    }
    return *this;
}

ostream& operator<<(ostream& os, const Matrix& other) {

    for (int i = 1; i <= other.row_num; ++i) {
        for (int j = 1; j <= other.column_num; ++j) {
            os << other.data[(i-1) * other.column_num + (j-1)] << " ";
        }
        os << endl;
    }
    return os;
}

Matrix operator*(int a,const Matrix& other )
{
    Matrix temp(other);
    for (int i = 0; i < other.row_num*other.column_num; i++)
    {
        temp.data[i] = a * other.data[i];
    }
    return temp;
}

Matrix Matrix::operator*(const Matrix& other) {
    Matrix result(row_num, other.column_num);
    for (int i = 1; i <= row_num; i++)
    {
        for (int j = 1; j <= other.column_num; j++)
        {
            result.data[(i-1) * result.column_num + j-1]=0;
            for (int k = 1; k <= column_num; k++)
            {
                result.data[(i-1) * result.column_num + j-1] += this->data[(i-1) * column_num + k-1] * other.data[(k-1) * other.column_num + j-1];
            }
        }
    }
    return result;
}

const Matrix& Matrix::operator*(const int& scalar) const {
    for (int i = 0; i < row_num*column_num; ++i) {
        data[i] = scalar*data[i];
    }
    return *this;
}

Formatting Matrix::SetFormat() const {
    Formatting f;
    f.flag = cout.setf(ios_base::fixed,ios_base::floatfield);
    f.pr = cout.precision(3);
    return f;
}

void Matrix::Restore(Formatting &f) const {
    cout.setf(f.flag,ios_base::floatfield);
    cout.precision(3);
}





