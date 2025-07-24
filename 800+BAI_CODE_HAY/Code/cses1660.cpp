#include <bits/stdc++.h>
using namespace std;
#define int long long
unordered_map <int , int> f;

main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,x; cin >> n >> x;
    int res=0,s=0;
    f[0]=1;
    for (int i=1;i<=n;i++)
    {
        int ai;
        cin >> ai;
        s+=ai;
        res+=f[s-x];
        f[s]+=1;
    }
    cout << res;
    return 0;
}
