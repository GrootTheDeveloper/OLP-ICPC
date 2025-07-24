#include <bits/stdc++.h>
using namespace std;
#define int long long
vector <int> vi;
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
        int ai;
        cin >> ai;
        vi.push_back(ai);
    }
    sort(vi.begin(),vi.end());
    int res=0;
    for (auto it=vi.begin();it!=vi.end();it++)
    {
        auto x=it;
        x++;
        auto k=upper_bound(x,vi.end(),m-(*it));
        res+=k-x;
    }
    cout << res;

}
