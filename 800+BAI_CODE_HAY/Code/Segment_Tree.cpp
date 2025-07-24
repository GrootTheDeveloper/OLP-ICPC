#include <bits/stdc++.h>
using namespace std;

int a[10]={0, 1, 2, 3, 5, 8, 7, 4, 6};
int t[4*10];

void build(int id, int l, int r){

    if (l==r) return t[id]=a[l],void();
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    t[id]=t[id*2]+t[id*2+1];
}
int get(int id, int l, int r, int u, int v)
{
    if (r<u || l>v) return 0;
    if (u<=l && r<=v)
        return t[id];
    int mid=(l+r)/2;
    int t1=get(id*2, l, mid, u, v);
    int t2=get(id*2+1, mid+1, r, u, v);
    return t1+t2;
}
main()
{
    int n=8;
    build(1,1,n);
    cout << get(1,1,n,1,3);

}
