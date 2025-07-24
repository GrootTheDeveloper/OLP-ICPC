#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int lua[N],nuoc[N],cay[N],dp_lua[N],dp_nuoc[N],dp_cay[N];
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    freopen("E.INP","r",stdin);
    freopen("E.OUT","w",stdout);
    int k; cin >> k;
    for (int i=1;i<=k;i++) cin >> lua[i];
    for (int i=1;i<=k;i++) cin >> nuoc[i];
    for (int i=1;i<=k;i++) cin >> cay[i];
    dp_nuoc[1]=nuoc[1];
    dp_lua[1]=lua[1];
    dp_cay[1]=cay[1];
    for (int i=2;i<=k;i++)
    {
        dp_lua[i]=max({dp_lua[i-1],dp_nuoc[i-1]+lua[i],dp_cay[i-1]-lua[i]});
        dp_nuoc[i]=max({dp_nuoc[i-1],dp_cay[i-1]+nuoc[i],dp_lua[i-1]-nuoc[i]});
        dp_cay[i]=max({dp_cay[i-1],dp_lua[i-1]+cay[i],dp_nuoc[i-1]-cay[i]});
    }
    cout << max({dp_cay[k],dp_lua[k],dp_nuoc[k]});
}
