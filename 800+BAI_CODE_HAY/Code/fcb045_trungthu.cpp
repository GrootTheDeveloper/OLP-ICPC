#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m; cin >> n >> m;
    int sum=0,MIN=1e9;
    for (int i=1;i<=n;i++)
    {
        int ai; cin >> ai;
        sum+=ai;
        MIN=min(ai,MIN);
    }
    return cout << n+(m-sum)/MIN,0;
}
