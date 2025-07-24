#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    double x=(-1+sqrt(1+8*n))/2;
    long long y=(int) x;
    if (x==y) cout << y;
    else cout << y+1;

    return 0;
}
