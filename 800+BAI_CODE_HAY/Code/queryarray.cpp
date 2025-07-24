#include <bits/stdc++.h>
using namespace std;
int d[100005];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,q; cin >> n >> q;
    while (q--)
    {
        int type,l,r,x;
        cin >> type >> l >> r >> x;
        if (type==1) d[l]+=x,d[r+1]-=x;
        else d[l]-=x,d[r+1]+=x;
    }
    int res=0;
    for (int i=1;i<=n;i++) res+=d[i],cout << res << ' ';
    return 0;
}
