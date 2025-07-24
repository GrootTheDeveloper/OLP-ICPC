#include <bits/stdc++.h>
using namespace std;
#define int long long
struct dta{ int bg,ed;};
int a[100005];
vector <dta> vi;
bool cmp(dta a, dta b)
{
    return a.ed-a.bg>b.ed-b.bg;
}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m,l; cin >> n >> m >> l;
    for (int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
    {
        dta x;
        x.bg=i;
        x.ed=upper_bound(a+i,a+n+1,a[i]+l)-a-1;
        if (!vi.size()) {vi.push_back(x);continue;}
        dta y=vi.back();
        if (y.ed>=x.bg && y.ed-y.bg<x.ed-x.bg) vi.back().ed=x.bg-1,vi.push_back(x);
        else if (y.ed<x.bg) vi.push_back(x);
    }
    sort(vi.begin(),vi.end(),cmp);
    int res=0;
    for (int i=0;i<vi.size();i++)
    {
        if (m>0 & vi[i].ed-vi[i].bg>=0) res+=vi[i].ed-vi[i].bg+1,m--;
    }
    cout << res;

}
