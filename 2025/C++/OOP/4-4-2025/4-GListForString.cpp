#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int MAX_LENGTH = 100;
class GListForString{
private:
    int length;
    string data[MAX_LENGTH];
public:
    GListForString();
    bool isEmpty() const;
    bool isFull() const;
    int size() const;
    void insert(string item);
    void print() const;
};

GListForString::GListForString(){
    length = 0;
}

bool GListForString::isEmpty() const {
    return length == 0;
}

bool GListForString::isFull() const {
    return length == MAX_LENGTH;
}

int GListForString::size() const {
    return length;
}

void GListForString::insert(string item) {
    if (!isFull())
        data[length++] = item;
    else 
        cout << "List is full, cannot insert new item!";
}

void GListForString::print() const {
    cout << "GListForString: ";
    for (int i = 0; i < length; i++) {
        cout << data[i] << " ";
    }
}
int main() {
    GListForString stringList;
    stringList.insert("ABC");
    stringList.insert("DEF");
    stringList.insert("GHI");
    stringList.print();
    return 0;
}