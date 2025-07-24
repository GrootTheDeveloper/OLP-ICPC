#include <bits/stdc++.h>
using namespace std;
#define maxn 100005
#define ll long long

ll a[maxn],t[maxn*4],n,q;

void build(int id, int l, int r)
{
    if (l==r) return t[id]=a[l],void();
    int mid=(l+r)/2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    t[id]=t[id*2]+t[id*2+1];
}
ll get(int id, int l, int r, int u, int v)
{
    if (l>v || r<u) return 0;
    if (u<=l && r<=v) return t[id];
    int mid = (l+r)/2;
    return ( get(id*2,l,mid,u,v) + get(id*2+1,mid+1,r,u,v));
}
void update(int id, int l, int r, int p)
{
    if (p<l || p>r) return;
    if (l==r)
    {
        t[id]=a[p];
        return;
    }
    int mid = (l+r)/2;
    if (p<=mid) update(id*2,l,mid,p);
    else update(id*2+1,mid+1,r,p);
    t[id]=t[id*2]+t[id*2+1];
}


int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    build(1,1,n);
    while (q--)
    {
        int type, h, k;
        cin >> type >> h >> k;
        if (type==1)
        {
            a[h]+=k;
            update(1,1,n,h);
        }
        else cout << get(1,1,n,h,k)<<endl;
    }
    return 0;
}
