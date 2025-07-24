#include <bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int a[N],f[N],d;
void add(int id) { f[id]++;d+=(f[id]==2);}
void del(int id) {f[id]--;d-=(f[id]==1);}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    for (int i=1;i<=n;i++) {cin >> a[i] ; add(a[i]);}
    del(a[1]);
    int r=1,ans=1e9;
    for (int l=1;l<=n;l++)
    {
        while (r<n && d)
        {
            r++;
            del(a[r]);
        }
        if (d==0) ans=min(ans,r-l+1);
        add(a[l]);
    }
    cout << ans;

}
