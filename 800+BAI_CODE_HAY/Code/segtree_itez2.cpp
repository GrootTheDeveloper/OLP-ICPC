#include <bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;

long long  n,q,a[maxn],t[maxn*4];
void build(int id, int l, int r)
{
    if (l==r) return t[id]=a[l],void();
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    t[id]=t[id*2]+t[id*2+1];
}

ll get(int id, int l, int r, int u, int v)
{
    if (r<u || l>v) return 0;
    if (u<=l && r<=v) return t[id];
    int mid = (l+r)/2;
    ll t1=get(id*2,l,mid,u,v);
    ll t2=get(id*2+1,mid+1,r,u,v);
    return t1+t2;
}

void update(int id, int l, int r, int p)
{
    if (p>r || p<l) return;
    if (l==r){
        t[id]=a[p];
        return;
    }
    int mid = (l+r)/2;
    update(id*2,l,mid,p);
    update(id*2+1,mid+1,r,p);
    t[id]=t[id*2]+t[id*2+1];

}
int main()
{
    cin >> n >> q;
    for (int i=1;i<=n;i++)
        a[i]=0;
    //build(1,1,n);
    while (q--)
    {
        long long t,h,k;
        cin >> t >> h >> k;
        if (t==1){
            a[h]=k;
            update(1,1,n,h);
        }
        else
        {
            cout << getSum(1,1,n,h,k)<< endl;
        }
    }

    return 0;
}

