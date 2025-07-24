// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
#define maxn 50005
#define ll long long
ll a[maxn],t[maxn*4],lazy[maxn*4],n,m;
void update(int id, int l, int r, int u, int v, int k)
{
    if (l>v || r<u) return;
    if (u<=l && r<=v)
    {
        t[id]+=k;
        lazy[id]+=k;
        return;
    }
    int mid=(l+r)/2;
    update(id*2,l,mid,u,v,k);
    update(id*2+1,mid+1,r,u,v,k);
    t[id]=max(t[id*2],t[id*2+1])+lazy[id];
}
ll get(int id, int l, int r, int u, int v)
{
    if (l>v || r<u) return INT_MIN;
    if (u<=l && r<=v) return t[id];
    int mid=(l+r)/2;
    return max( get(id*2,l,mid,u,v) , get(id*2+1,mid+1,r,u,v))+lazy[id];

}


int main() {
    cin >> n >> m;
    while (m--)
    {
        int t,x,y,k;
        cin >> t >> x >> y;
        if (t)
            cout << get(1,1,n,x,y) << endl;
        else
        {
            cin >> k;
            update(1,1,n,x,y,k);
        }


    }


    return 0;
}
