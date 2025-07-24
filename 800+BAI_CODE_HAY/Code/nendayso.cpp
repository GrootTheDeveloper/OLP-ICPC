#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode =1e9;

int Pow(int a, int b)
{
    int res=1;
    while (b)
    {
        if (b&1) res=(res*a)%mode;
        a=(a*a)%mode;
        b>>=1;
    }
    return res;
}
main()
{
    int n; cin >> n;
    cout << (n+1)%mode*Pow(2,n-2)%mode;
}
