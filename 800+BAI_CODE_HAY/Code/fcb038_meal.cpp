#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5;
int t[N*4],a[100005];

void up(int id, int l, int r, int u, int d)
{
    if (u<l || u>r) return;
    if (l==r) return t[id]+=d,void();
    int mid=(l+r)/2;
    up(id*2,l,mid,u,d);
    up(id*2+1,mid+1,r,u,d);
    t[id]=max(t[id*2],t[id*2+1]);
}
int get()
{
    return t[1];
}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int te; cin >> te;
    while (te--)
    {
        int n,k; cin >> n >> k;
        for (int i=1;i<=n;i++) cin >> a[i];
        int l=1,ans=0;
        for (int i=1;i<=n;i++)
        {
            up(1,1,N,a[i],1);
            while (i-l+1-get()>k) up(1,1,N,a[l],-1),l++;
            ans=max(ans,i-l+1);
        }
        cout << ans << endl;
        for (int i=l;i<=n;i++) up(1,1,N,a[i],-1);
    }
}
