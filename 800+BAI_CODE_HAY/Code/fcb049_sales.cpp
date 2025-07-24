#include <bits/stdc++.h>
using namespace std;
unordered_map<int,int> f;
vector<int> vi;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    for (int i=1;i<=n;i++)
    {
        int ai;
        cin >> ai;
        if (f[ai]==0) vi.push_back(ai);
        f[ai]++;
    }
    int res=0;
    for (int it : vi)
    {
        if (f[it]==1) return cout << -1,0;
        res+=f[it]/3+(f[it]%3!=0);
    }
    return cout << res,0;
}
