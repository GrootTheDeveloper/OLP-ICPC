#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
const int oo=1e9+7;
int a[maxn],d[maxn];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,s; cin >> n >> s;
    for (int i=1;i<=n;i++) cin >> a[i];
    int l=1,res=oo;
    for (int r=1;r<=n;r++)
    {
        for (int j=s;j>=a[r];j--)
            d[j]=max(d[j],d[j-a[r]]);
        d[a[r]]=r;
        if (d[s]>=l)
        {
            res=min(res,r-d[s]+1);
            l=d[s]+1;
        }
    }
    if (res==oo) res=-1;
    return cout << res,0;

}


