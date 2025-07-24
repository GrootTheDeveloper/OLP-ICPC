#include <bits/stdc++.h>
using namespace std;
unordered_map <int, int> f;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,res=0,x; cin >> n >> x;
    for (int i=1; i<=n; i++)
    {
        int ai;
        cin >> ai;
        res+=f[x-ai];
        f[ai]++;
    }
    return cout << res,0;
}
