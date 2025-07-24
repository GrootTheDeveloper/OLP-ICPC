#include <bits/stdc++.h>
using namespace std;

int main()
{

    int a,b,c,n; cin >> a >> b >> c >> n;
    if (c>a||c>b||(a+b-c)>=n) return cout << -1,0;
    return cout << n-(a+b-c),0;
}
