#include <bits/stdc++.h>
using namespace std;
#define int long long

main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    freopen("MINNUM.INP","r",stdin);
    freopen("MINNUM.OUT","w",stdout);
    string s; cin >> s;
    int res=0,mi=0,ma=0;
    for (char c : s)
    {
        if (c=='>') res--;
        else res++;
        mi=min(mi,res);
        ma=max(ma,res);

    }
    if (mi<0) ma+=abs(mi);
    cout << ma;
}
