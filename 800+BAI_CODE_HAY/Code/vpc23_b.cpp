#include <bits/stdc++.h>
using namespace std;
#define int long long
vector <int> f;
struct dta{ int fi,se;};
dta a[1000006];
bool cmp(dta a, dta b) { return a.fi<b.fi;}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while (t--)
    {
        vector <int> vi(f);
        int c,m,n; cin >> c >> m >> n;
        for (int i=1; i<=m;i++) {int ai; cin >> ai; vi.push_back(ai);}
        sort(vi.begin(),vi.end());
        for (int i=1;i<=n;i++) cin >> a[i].fi >> a[i].se;
        sort(a+1,a+n+1,cmp);
        int k=c,j=0,res=0;
        for (int i=1;i<=n;i++)
        {
            if (a[i].fi>vi[j] && j<m) k=c,j++;
            if (a[i].se<=k) res+=a[i].se,k-=a[i].se;
        }
        cout << res << endl;


    }
}
