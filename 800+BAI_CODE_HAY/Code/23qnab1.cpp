#include <bits/stdc++.h>
using namespace std;
#define int long long
bool cp(int a)
{
    return (int)sqrt(a)==sqrt(a);
}
main()
{
    freopen("SQUARE.INP","r",stdin);
    freopen("SQUARE.OUT","w",stdout);
    int n,k; cin >> n >> k;
    //int res=0;
    //for (int i=k;i<=n;i++) if (cp(i)) res++;
    //cout << res << ' ';
    cout << (int)sqrt(n)-(int)sqrt(k-1);
}
