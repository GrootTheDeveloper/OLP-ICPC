#include <iostream>
using namespace std;

class PhanSo {
    int tu, mau;
    
    int gcd(int a, int b)  { return (b == 0) ? a : gcd(b, a % b);}
    void rutGon();

public: 
    PhanSo() {tu = 0; mau = 1;}
    PhanSo(int, int);
    PhanSo operator + (PhanSo);
    PhanSo operator + (int);
    friend PhanSo operator + (int, PhanSo);
    bool operator == (PhanSo);
    bool operator < (PhanSo);
//    PhanSo& operator = (PhanSo);
};

PhanSo PhanSo::operator + (int k) {
    return PhanSo(tu + k * mau, mau);
}

void PhanSo::rutGon(){
    int g = gcd(tu,mau);
    tu/=g;
    mau/=g;
    if (mau < 0) {
        mau = -mau;
        tu = -tu;
    }
}

PhanSo::PhanSo(int t, int m) {
    tu = t;
    mau = m;
    rutGon();
}

PhanSo PhanSo::operator + (PhanSo b) {
    return PhanSo(tu * b.mau + mau*b.tu, mau * b.mau);
}

PhanSo operator +(int k, PhanSo that) {
    PhanSo temp(k,1);
    return temp + that;
}

bool PhanSo::operator == (PhanSo b){
    return tu * b.mau == mau*b.tu;
}

bool PhanSo::operator < (PhanSo b) {
    return tu *b.mau < mau*b.tu;
}
int main() {
    PhanSo a(2,3),b(5,6);
    a = b;   
}