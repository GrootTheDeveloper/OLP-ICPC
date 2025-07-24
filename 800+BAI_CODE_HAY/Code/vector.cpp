#include <bits/stdc++.h>
using namespace std;


int main()
{
    vector<int> arr={1,2,3,4,5};
    arr.push_back(6);
    arr.push_back(7);
    for (int i=0;i<arr.size();i++)
        cout << arr[i] << " ";
    cout << endl;
    arr.erase(arr.begin()+1,arr.begin()+3);
    for (int i=0;i<arr.size();i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
