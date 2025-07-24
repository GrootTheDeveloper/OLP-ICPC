#include <bits/stdc++.h>
using namespace std;
#define int long long
struct dta{int cnt,sum;};
unordered_map <int,dta> f;
int sums,res=-1e18;
void solve(int ai)
{
    if (f[ai].cnt) res=max(res,sums-f[ai].sum+ai),f[ai].sum=min(f[ai].sum,sums);
    else f[ai].sum=sums,f[ai].cnt++;
}       
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    for (int i=1;i<=n;i++)
    {
        int ai; cin >> ai;
        sums+=ai;
        solve(ai);   
    }
    cout << res;
}
