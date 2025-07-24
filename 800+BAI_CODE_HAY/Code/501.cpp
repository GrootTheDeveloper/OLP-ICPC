#include <bits/stdc++.h>
using namespace std;
#define int long long
int vec[10000];

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int a,b; cin >> a >> b;
    int lim = 0;
    for (int i = a; i <= b; i+=a)
        if (b % i == 0) vec[++lim] = i;
    int res = 0;
    for (int i = 1; i <= lim; i++)
        for (int j = i + 1; j <= lim; j++)
        {
            int gcd = __gcd(vec[i],vec[j]);
            if (gcd == a && (vec[i] * vec[j]) / gcd == b) res++;
        }
    cout << res * 2;
}
