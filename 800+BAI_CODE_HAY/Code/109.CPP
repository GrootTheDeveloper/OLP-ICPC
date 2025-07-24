#include <bits/stdc++.h>
using namespace std;
#define int long long


int mul(int a, int b, int mode)
{
    int res = 0;
    while (b)
    {
        if (b & 1) res = (res + a) % mode;
        a = (a + a) % mode;
        b /= 2;
    }
    return res;
}
int power(int a, int b, int mode)
{
    int res = 1;
    while (b)
    {
        if (b & 1) res = mul(res, a, mode);
        a = mul(a,a,mode);
        b >>= 1;
    }
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int a,b,c; cin >> a >> b >> c;
    cout << power(a,b,c);
}