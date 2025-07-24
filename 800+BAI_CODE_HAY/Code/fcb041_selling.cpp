#include <bits/stdc++.h>
using namespace std;
int f[11111];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,t,q; cin >> n >> t >> q;
    int res=0;
    for (int i=1;i<=q;i++)
    {
        int ai,vi; cin >> ai >> vi;
        if (vi>f[ai])
        {
            res=res-f[ai]+vi;
            f[ai]=vi;
        }
        if (res>=t) return cout << i,0;
    }
    return cout << -1,0;
}
