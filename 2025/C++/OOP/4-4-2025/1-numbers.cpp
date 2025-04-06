#include <iostream>
#include <vector>
using namespace std;

template<class T>
void sort(vector<T>& v)
{
    size_t n = v.size();
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                T temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

int main() {
    //vector<int> numbers = { 5, 3, 8, 1, 2 };
    vector<long> numbers = { 5, 3, 8, 1, 2 };

    sort(numbers); // dùng hàm sort bạn viết bằng template
    
    for (int num : numbers) {
        cout << num << " ";
    }
    return 0;
}