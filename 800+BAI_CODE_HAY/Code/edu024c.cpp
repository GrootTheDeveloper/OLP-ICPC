#include <bits/stdc++.h>
using namespace std;
#define int long long
unordered_map <int,int> f;
int a[100005];
vector <int> root[100005],s;


void Try(int x)
{
    s.push_back(a[x]);
    if (root[x].empty()) return;
    for (int c : root[x]) Try(c);
}
void solve(int x)
{
    s.erase(s.begin(),s.end());
    Try(x);
    int res=0,max_size=0;
    unordered_map <int,int> cnt;
    for (int c : s) cnt[c]++,max_size=max(max_size,cnt[c]);
    for (int c : s) if (cnt[c]==max_size) res+=c,cnt[c]=0;
    cout << res << ' ';

}

main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    freopen("WAW.INP","r",stdin);
    freopen("WAW.OUT","w",stdout);
    int n,lim=0; cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
        f[a[i]]++;
        lim=max(lim,f[a[i]]);
    }

    int x,y;
    for (int i=1;i<n;i++)
    {
        cin >> x >> y;
        root[x].push_back(y);
    }
    int res=0;
    for (int i=1;i<=n;i++) if (f[a[i]]==lim) res+=a[i],f[a[i]]=0;
    cout << res << ' ';

    for (int i=2;i<=n;i++)
        solve(i);

}
