#include <bits/stdc++.h>
using namespace std;
#define int long long
unordered_map <int,vector<int>> f;
int pf[100005];

main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    int MAX=-1e18;
    for (int i=1;i<=n;i++)
    {
        int ai;
        cin >> ai;
        pf[i]=pf[i-1]+ai;
        for (int it : f[ai])
            MAX=max(MAX,pf[i]-pf[it-1]);
        f[ai].push_back(i);

    }
    cout << MAX;
}
