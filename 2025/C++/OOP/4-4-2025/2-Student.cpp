#include <iostream>
#include <vector>
using namespace std;

template<class T>
void sort(vector<T>& v, bool DESC = true)
{
    size_t n = v.size();
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = 0; j < n - i - 1; j++) {
            if (!DESC) {
                if (v[j] > v[j + 1]) {
                    T temp = v[j];
                    v[j] = v[j + 1];
                    v[j + 1] = temp;
                }
            }
            else {
                if (v[j] < v[j + 1]) {
                    T temp = v[j];
                    v[j] = v[j + 1];
                    v[j + 1] = temp;
                }
            }
        }
    }
}

class Student {
    public:
        string name;
        int score;

        Student(string n, int s) : name(n), score(s) {}

        bool operator > (const Student& other) const {
            return score > other.score;
        }

        bool operator < (const Student& other) const {
            return score < other.score;
        }
        
        void print() const {
            cout << name << "(" << score << ")" << endl; 
        }
};

int main() {
    //vector<int> numbers = { 5, 3, 8, 1, 2 };
    vector<Student> student = { {"Phao", 5}, {"Viruss", 8}, {"Peter", 1} };

    sort(student); 
   
    for (auto s : student) {
        s.print();  
    }

    sort(student, false);
    for (auto s : student) {
        s.print();
    }
    return 0;
}