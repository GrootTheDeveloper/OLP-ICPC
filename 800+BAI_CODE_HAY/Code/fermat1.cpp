#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1000006];
const int mode=2004010501;
int power(int a, int b)
{
    int res=1;
    while (b)
    {
        if (b&1) res=res*a%mode;
        a=a*a%mode;
        b/=2;
    }
    return res;
}
main()
{
    int n; cin >> n;
    int res,ai;
    cin >> res;
    n--;
    while (n--)
    {
        cin >> ai;
        res=power(res,ai);

    }
    cout << res;
}
