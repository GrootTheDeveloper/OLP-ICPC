#include <bits/stdc++.h>
using namespace std;

void qery()
{
    int n; cin >> n;
    vector<int> f(n+1,0);
    int res=0,temp=0;
    for (int i=1;i<=n;i++)
    {
        int ai; cin >> ai;
        if (f[ai]==0) f[ai]++,res++;
        else temp++;
    }
    int k; cin >> k;
    if (k<=temp) cout << res << '\n';
    else cout << res-(k-temp) << '\n';

}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while (t--) qery();
}
