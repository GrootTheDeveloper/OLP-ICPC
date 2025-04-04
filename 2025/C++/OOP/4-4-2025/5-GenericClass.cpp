#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int MAX_LENGTH = 100;

class Student {
    public:
        string name = "";
        int score = 0;;

        Student() {
        };

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

template<class T>
class GList{
private:
    int length;
    T data[MAX_LENGTH];
public:
    GList();
    bool isEmpty() const;
    bool isFull() const;
    int size() const;
    void sort(bool DESC = true);
    void insert(T item);
    void print() const;
    friend ostream& operator<<(ostream& os, const Student& dt);

};
ostream& operator<<(ostream& os, const Student& dt) {
    os << dt.name << " " << dt.score;
    return os;
} 

template<class T>
GList<T>::GList(){
    length = 0;
}


template<class T>
void GList<T>::sort(bool DESC) {
    for (size_t i = 0; i < length - 1; i++) {
        for (size_t j = 0; j < length - i - 1; j++) {
            if (!DESC) {
                if (data[j] > data[j + 1]) {
                    T temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
            else {
                if (data[j] < data[j + 1]) {
                    T temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
    }
}

template<class T>
bool GList<T>::isEmpty() const {
    return length == 0;
}

template<class T>
bool GList<T>::isFull() const {
    return length == MAX_LENGTH;
}

template<class T>
int GList<T>::size() const {
    return length;
}

template<class T>  
void GList<T>::insert(T item) {
    if (!isFull())
    data[length++] = item;
    else 
    cout << "List is full, cannot insert new item!";
}

template<class T>  
void GList<T>::print() const {
    cout << "GList: " << endl;
    for (int i = 0; i < length; i++) {
         cout << data[i] << endl;
    }
}
int main() {
    GList<Student> student;
    student.insert({"Khang",7});
    student.insert({"Khoa", 8});
    student.insert({"Hoang", 9});
    student.sort(0);
    student.print();
    student.sort(1);
    student.print();
    return 0;
}