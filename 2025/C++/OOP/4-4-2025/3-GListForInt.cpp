#include <iostream>
#include <vector>
using namespace std;
const int MAX_LENGTH = 100;
class GListForInt{
private:
    int length;
    int data[MAX_LENGTH];
public:
    GListForInt();
    bool isEmpty() const;
    bool isFull() const;
    int size() const;
    void insert(int item);
    void print() const;
};

GListForInt::GListForInt(){
    length = 0;
}

bool GListForInt::isEmpty() const {
    return length == 0;
}

bool GListForInt::isFull() const {
    return length == MAX_LENGTH;
}

int GListForInt::size() const {
    return length;
}

void GListForInt::insert(int item) {
    if (!isFull())
        data[length++] = item;
    else 
        cout << "List is full, cannot insert new item!";
}

void GListForInt::print() const {
    cout << "GListForInt: ";
    for (int i = 0; i < length; i++) {
        cout << data[i] << " ";
    }
}
int main() {
    GListForInt intList;
    intList.insert(10);
    intList.insert(15);
    intList.insert(20);
    intList.print();
    return 0;
}