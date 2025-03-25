
/*
a) Định nghĩa lớp số tự nhiên lớn (lên đến 512 chữ số)
b) Định nghĩa lớp số nguyên lớn có giá trị (không kể dấu) 
lên đến 512 chữ số

Các xử lý cơ bản bao gồm: nhập/xuất, +, *, v.v... 

Lưu ý: Khai báo và cài đặt lớp số nguyên kế thừa lớp số tự nhiên
*/

#include <iostream>
#include <string>
using namespace std;
const int maxLen = 512;
class Natural {
    //char number[maxLen];
    string number; 
public:
    Natural(string b = "0") {
        if (b.empty()) b = "0";
        number = b;
    }

    void input(){
        cin >> number;
    }
    void output(){
        cout << number << endl;
    }
    
    Natural operator + (const Natural& other) {
        int len = max(number.size(), other.number.size());
        
        reverse(number.begin(), number.end());
        reverse(other.number.begin(), other.number.end());

        while(number.size() < len) {
            number.push_back('0');
        }
        while(other.number.size() < len) {
            number.push_back('0');
        }

        int carry = 0;
        for (int i = 0; i < len; i++) {
            int temp = number[i] + other.number[i] - '0' * 2;
        }
    }
};


class Interger : public Natural {

};

int main() {
    return 0;
}
