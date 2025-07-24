#include <bits/stdc++.h>
using namespace std;
#define int long long
int cnt[1000006];
vector <int> v;
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n; cin >> n;
    int x;
    for (int i=1;i<=n;i++)
    {
        cin >> x;
        cnt[x]++;
        if (cnt[x]==2) v.push_back(x),cnt[x]=0;
    }
    if (v.size()<2) return cout << -1,0;
    sort(v.begin(),v.end(),greater<int>());
    cout << (v[0]+v[1])*2;

}
