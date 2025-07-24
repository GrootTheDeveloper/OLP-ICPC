#include <bits/stdc++.h>
using namespace std;
#define maxn 50004

int n,a[maxn],mi[maxn*4],ma[maxn*4],q;

void build(int id,int l,int r){
    if (l==r){
        mi[id]=ma[id]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    mi[id]=min(mi[id*2],mi[id*2+1]);
    ma[id]=max(ma[id*2],ma[id*2+1]);
}

int get(int id, int l, int r, int u, int v, bool q){
    if (r<u || l>v)
    {
        if (!q) return INT_MIN;
        else return INT_MAX;
    }
    if (u<=l && r<=v)
    {
        if (!q) return ma[id];
        if (q) return mi[id];
    }

    int mid=(l+r)/2;
    int t1=get(id*2,l,mid,u,v,q);
    int t2=get(id*2+1,mid+1,r,u,v,q);
    if (!q) return max(t1,t2);
    else return min(t1,t2);
}

int main()
{

    cin >> n >> q;
    for (int i=1;i<=n;i++)
        cin >> a[i];
    build(1,1,n);
    while (q--){
        int u,v;
        cin >> u >> v;
        int getmax=get(1,1,n,u,v,0);
        int getmin=get(1,1,n,u,v,1);
        cout << getmax-getmin<< endl;
    }
    return 0;
}
