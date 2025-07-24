#include <bits/stdc++.h>
using namespace std;
const int oo=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while (t--)
    {
        int n,k; cin >> n >> k;
        int MIN=oo,MAX=-oo;
        for (int i=1;i<=n;i++)
        {
            int ai;
            cin >> ai;
            MIN=min(MIN,ai);
            MAX=max(MAX,ai);
        }
        if (MIN<=k && MAX>=k) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
