#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x,y,z; cin >> x >> y >> z;
    int b=(x-z+y)/2;
    int a=x-b,c=y-b;
    return cout << a << ' ' << b << ' ' << c,0;
}
