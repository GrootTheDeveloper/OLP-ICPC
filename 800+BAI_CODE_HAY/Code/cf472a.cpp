#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    for (int i=4;i<=n/2;i++)
        if ((i%2==0 || i%3==0) && ((n-i)%2==0 || (n-i)%3==0)) return cout << i << ' ' << n-i,0;
}
