#include <bits/stdc++.h>
using namespace std;
#define int long long

int res(int n)
{
    return 45*(n/9)+((n%9)*(n%9+1)/2);
}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while (t--)
    {
        int l,r; cin >> l >> r;
        cout << res(r)-res(l-1) << endl;
    }
}
