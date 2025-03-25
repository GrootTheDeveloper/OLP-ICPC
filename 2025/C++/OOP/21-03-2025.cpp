#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v(100, 0);
    cout << v.capacity() << endl;
    v.push_back(1);
    cout << v.size() << " " << v.capacity() << endl;
    v.reserve(60);
    cout << v.size() << " " << v.capacity() << endl;
    cout << "Is empty:" << " " << (v.empty() ? "Yes" : "No") << endl;
}
