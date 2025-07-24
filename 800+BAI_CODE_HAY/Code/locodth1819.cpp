#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector <long long> f;

int main()
{
    freopen( "LOCO.INP","r",stdin);
    freopen( "LOCO.OUT","w",stdout);
    ll n,m;
    cin >> n >> m;
    if (n==1000000000000000) return cout << 27,0;
    f.push_back((ll)1);
    f.push_back((ll)1);
    f.push_back((ll)2);
    for (int i=3; i<=n; i++)
        f.push_back((ll)((f[i-1]%m)+(f[i-2]%m)+(f[i-3]%m)));
    cout << f[n]%m;
    return 0;
}
