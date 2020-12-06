#include <iostream>
#include <random>
#include <chrono>
#include <iomanip>
#include "Matrix.h"
using namespace std;

int main() {

    int a, b;
    cin >> a >> b;
    float* c = new float[a*b];
    random_device randomDevice;
    mt19937 gen(randomDevice());
    uniform_real_distribution<float> dis(-3.0f, 3.0f);
    for (int i = 0; i < a*b; i++)
    {
        c[i] = dis(gen);
    }
    Matrix A = Matrix(a,b,c);
    Formatting flag = A.SetFormat();
    cout<<A<<endl;
    A.Restore(flag);
    cin >> a >> b;
    float* d = new float[a*b];
    for (int i = 0; i < a * b; i++)
    {
        d[i] = dis(gen);
    }
    Matrix B = Matrix(a, b, d);
    flag = B.SetFormat();
    cout<<B<<endl;
    B.Restore(flag);
    Matrix C = A * B;
    flag = C.SetFormat();
    cout << "A * B = : \n" << C<<endl;
    C.Restore(flag)
;
    int scalar = 15;
    Matrix D = scalar*A;
    flag = D.SetFormat();
    cout<<scalar<<" * A = \n"<<D<<endl;
    D = A*scalar;
    cout<<"A * "<<scalar<<" = \n"<<D<<endl;
    D.Restore(flag);
    delete[] c;
    delete[] d;
    return 0;
}
