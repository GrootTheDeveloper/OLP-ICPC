#include <bits/stdc++.h>
using namespace std;
#define int long long

int f[500005],n,k;
bool cnt[500005];
const int mode=1e9+7;



void sub1()
{
    vector <int> v;
    f[1]=1;
    for (int i=1;i<=n;i++) if (cnt[i]) v.push_back(i);
    for (int i=1;i<=n;i++)
    {
        for (int c : v)
            if (c<=i) f[i]=(f[i]+f[i-c])%mode;
        else break;
    }
    cout << f[n];
}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n >> k;
    for (int i=1;i<=k;i++)
    {
        int l,r; cin >> l >> r;
        for (int j=l;j<=r;j++) cnt[j]=true;
    }
    sub1();
}
