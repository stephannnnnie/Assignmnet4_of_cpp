#pragma once
#include <iostream>

#ifndef ASSIGNMENT4_MATRIX_H
#define ASSIGNMENT4_MATRIX_H
using namespace std;
struct Formatting{
    std::ios_base::fmtflags flag;
    std::streamsize pr;
};
class Matrix {
private:
    int row_num;
    int column_num;
    float* data{};
public:
    Matrix();
    Matrix(int a, int b,float * c);
    Matrix(int a, int b);
    Matrix(const Matrix& mat);

    ~Matrix();
    Formatting SetFormat() const;
    void Restore(Formatting& f) const;

    Matrix& operator=(const Matrix& matrix);
    friend ostream& operator<<(ostream& os, const Matrix& other);
    Matrix operator*(const Matrix& other);
    const Matrix& operator*(const int& scalar) const;
    friend  Matrix operator *(int a, const Matrix& other);
};
#endif //ASSIGNMENT4_MATRIX_H
