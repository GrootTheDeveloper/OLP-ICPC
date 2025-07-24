#include <bits/stdc++.h>
using namespace std;
#define int long long
const int SIZE=1e6+7;

string s;
int k;
struct dta{
    int val,idx;
};

dta t[SIZE*4];
dta oo;

dta mer(dta a, dta b)
{
    if (a.val==b.val)
    {
        if (a.idx<b.idx) return a;
        else return b;
    }
    if (a.val>b.val) return a;
    else return b;
}
void build(int id, int l, int r)
{
    if (l==r) {
        t[id].idx=l;
        t[id].val=s[l-1]-'0';
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    t[id]=mer(t[id*2],t[id*2+1]);
}
dta get(int id, int l, int r, int u, int v)
{
    if (r<u || l>v) return oo;
    if (u<=l && r<=v) return t[id];
    int mid=(l+r)/2;
    return mer(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}


signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> s >> k;
    int n=s.size();
    oo.val=-1;
    k=n-k;
    build(1,1,n);
    int pos=1;
    for (int last=n-k+1;last<=n;last++)
    {
        dta node=get(1,1,n,pos,last);
        cout << node.val;
        pos=node.idx+1;
    }
}
