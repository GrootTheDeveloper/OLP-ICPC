#include <bits/stdc++.h>
using namespace std;
#define int long long
int f[1001][1001],w[1111],ti[1001][1001],res=INT_MAX,ans,t,s,k,c,n,m;
vector <int> d[1111];
bool vi[1111];
void Try(int u)
{
    vi[u]=true;
    int temp=ans;
    if (u==t) return res=min(res,ans),void();
    for (int v : d[u])
        if (vi[v]==false)
        {
            if (ti[u][v]==0 || ans+f[u][v]<=ti[u][v]-f[u][v] || ans>=ti[u][v]) ans+=f[u][v],Try(v);
            else ans+=f[u][v]+(ti[u][v]-ans),Try(v);
            ans=temp;

        }
}

main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("DISENTR.INP","r",stdin);
    freopen("DISENTR.OUT","w",stdout);
    cin >> n >> m;
    cin >> s >> t >> k >> c;
    for (int i=1;i<=c;i++) cin >> w[i];
    for (int i=1;i<=m;i++)
    {
        int x,y,l; cin >> x >> y >> l;
        f[x][y]=l;
        f[y][x]=l;
        d[x].push_back(y);
        d[y].push_back(x);
    }
    int sum=0;
    for (int i=1;i<c;i++) sum+=f[w[i]][w[i+1]], ti[w[i]][w[i+1]]=ti[w[i+1]][w[i]]=sum;
    ans=k;
    Try(s);
    cout << res-k;
}
