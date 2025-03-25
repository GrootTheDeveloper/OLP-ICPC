#include <iostream>
#include <cmath>

using namespace std;

struct Diem {
    double x, y;
};

// tính khoảng cách giữa hai điểm
double khoangCach(const Diem& d1, const Diem& d2) {
    return sqrt(pow(d2.x - d1.x, 2) + pow(d2.y - d1.y, 2));
}

class DaGiac {
protected:
    Diem dinh[100];  // tối đa 100 đỉnh
    int soDinh; 

public:
    DaGiac(const Diem ds[], int n) : soDinh(n) {
        if(ds != nullptr) {
            for (int i = 0; i < n; i++)
                dinh[i] = ds[i];
        }
    }

    virtual double dienTich() const = 0; 
    virtual double chuVi() const = 0;
    
    virtual void hienThi() const {
        cout << "Đa giác có các đỉnh: ";
        for (int i = 0; i < soDinh; i++)
            cout << "(" << dinh[i].x << ", " << dinh[i].y << ") ";
        cout << endl;
    }

    virtual ~DaGiac() {}
};

class TamGiac : public DaGiac {
public:
    TamGiac(const Diem& d1, const Diem& d2, const Diem& d3)
        : DaGiac(nullptr, 3) { 
        Diem temp[3] = {d1, d2, d3}; 
        for (int i = 0; i < 3; i++) 
            dinh[i] = temp[i]; 
    }

    double dienTich() const override {
        const Diem &d1 = dinh[0], &d2 = dinh[1], &d3 = dinh[2];
        return fabs(d1.x * (d2.y - d3.y) +
                    d2.x * (d3.y - d1.y) +
                    d3.x * (d1.y - d2.y)) / 2.0;
    }

    double chuVi() const override {
        return khoangCach(dinh[0], dinh[1]) +
               khoangCach(dinh[1], dinh[2]) +
               khoangCach(dinh[2], dinh[0]);
    }
};

class TuGiac : public DaGiac {
public:
    TuGiac(const Diem ds[], int n) : DaGiac(ds, n) {}

    TuGiac(const Diem& d1, const Diem& d2, const Diem& d3, const Diem& d4)
        : DaGiac(nullptr, 4) { 
        Diem temp[4] = {d1, d2, d3, d4}; 
        for (int i = 0; i < 4; i++) 
            dinh[i] = temp[i]; 
    }

    double dienTich() const override {
        TamGiac t1(dinh[0], dinh[1], dinh[2]);
        TamGiac t2(dinh[0], dinh[2], dinh[3]);
        return t1.dienTich() + t2.dienTich();
    }

    double chuVi() const override {
        return khoangCach(dinh[0], dinh[1]) +
               khoangCach(dinh[1], dinh[2]) +
               khoangCach(dinh[2], dinh[3]) +
               khoangCach(dinh[3], dinh[0]);
    }
};

class HinhChuNhat : virtual public TuGiac {
protected:
    double chieuDai;
    double chieuRong;
public:
    HinhChuNhat(const Diem& trenTrai, const Diem& trenPhai, 
                const Diem& duoiPhai, const Diem& duoiTrai)
        : TuGiac(trenTrai, trenPhai, duoiPhai, duoiTrai) {
        chieuDai = fabs(trenPhai.x - trenTrai.x);
        chieuRong = fabs(trenTrai.y - duoiTrai.y);
    }

    double dienTich() const override {
        return chieuDai * chieuRong;
    }

    double chuVi() const override {
        return 2 * (chieuDai + chieuRong);
    }
};

class HinhThoi : virtual public TuGiac {
protected:
    double duongCheo1;
    double duongCheo2;
public:
    HinhThoi(const Diem& d1, const Diem& d2, const Diem& d3, const Diem& d4)
        : TuGiac(d1, d2, d3, d4) {
        duongCheo1 = khoangCach(d1, d3);
        duongCheo2 = khoangCach(d2, d4);
    }

    double dienTich() const override {
        return (duongCheo1 * duongCheo2) / 2.0;
    }

    double chuVi() const override {
        return 4 * khoangCach(dinh[0], dinh[1]);
    }
};

class HinhVuong : public HinhChuNhat, public HinhThoi {
private:
    static Diem* khoiTaoDiem(const Diem& trenTrai, double canh) {
        static Diem temp[4];
        temp[0] = trenTrai;
        temp[1] = {trenTrai.x + canh, trenTrai.y};
        temp[2] = {trenTrai.x + canh, trenTrai.y - canh};
        temp[3] = {trenTrai.x, trenTrai.y - canh};
        return temp;
    }

    double doDaiCanh() const {
        return fabs(dinh[1].x - dinh[0].x);
    }
public:
    HinhVuong(const Diem& trenTrai, double canh)
        : TuGiac(khoiTaoDiem(trenTrai, canh), 4),
          HinhChuNhat(khoiTaoDiem(trenTrai, canh)[0],
                      khoiTaoDiem(trenTrai, canh)[1],
                      khoiTaoDiem(trenTrai, canh)[2],
                      khoiTaoDiem(trenTrai, canh)[3]),
          HinhThoi(khoiTaoDiem(trenTrai, canh)[0],
                   khoiTaoDiem(trenTrai, canh)[1],
                   khoiTaoDiem(trenTrai, canh)[2],
                   khoiTaoDiem(trenTrai, canh)[3])
    {
    }

    double dienTich() const override {
        return doDaiCanh() * doDaiCanh();
    }

    double chuVi() const override {
        return 4 * doDaiCanh();
    }
};

int main() {
    Diem d1 = {0, 0}, d2 = {4, 0}, d3 = {2, 3};
    TamGiac tamGiac(d1, d2, d3);
    cout << "Tam giác - Diện tích: " << tamGiac.dienTich() << ", Chu vi: " << tamGiac.chuVi() << endl;

    Diem q1 = {0, 4}, q2 = {6, 4}, q3 = {6, 0}, q4 = {0, 0};
    TuGiac tuGiac(q1, q2, q3, q4);
    cout << "Tứ giác - Diện tích: " << tuGiac.dienTich() << ", Chu vi: " << tuGiac.chuVi() << endl;

    HinhChuNhat hinhChuNhat(q1, q2, q3, q4);
    cout << "Hình chữ nhật - Diện tích: " << hinhChuNhat.dienTich() << ", Chu vi: " << hinhChuNhat.chuVi() << endl;

    HinhVuong hinhVuong({0, 4}, 4);
    cout << "Hình vuông - Diện tích: " << hinhVuong.dienTich() << ", Chu vi: " << hinhVuong.chuVi() << endl;

    return 0;
}
