#include <bits/stdc++.h>
#define maxn 100005
using namespace std;

int n,q,a[maxn],ma[maxn*4];
void build(int id, int l, int r)
{
    if (l==r) return ma[id]=a[l],void();
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    ma[id]=max(ma[id*2],ma[id*2+1])
}
int get(int id, int l, int r, int u, int v)
{
    if (r<u || l>v) return INT_MIN;
    if (u<=l && r<=v) return ma[id];
    int mid = (l+r)/2;
    int t1=get(id*2,l,mid,u,v);
    int t2=get(id*2+1,mid+1,r,u,v);
    return max(t1,t2);
}
void update(int id, int l, int r, int p)
{
    if (p>r || p<l) return;
    if (l==r) return ma[id]=a[p],void();
    int mid = (l+r)/2;
    update(id*2,l,mid,p);
    update(id*2+1,mid+1,r,p);
    ma[id]=max(ma[id*2],ma[id*2+1]);

}
int main()
{
    cin >> n;
    for (int i=1;i<=n;i++)
        cin >> a[i];
    cin >> q;
    while (q--)
    {
        cin >> t >> h >> k;
        if (t==1){
            a[h]=k;
            update(1,1,n,h);
        }
        else
        {
            cout << get(1,1,n,h,k);
        }
    }
    return 0;
}
