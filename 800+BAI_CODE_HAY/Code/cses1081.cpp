#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e6+7;
int f[M],a[M];

main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,MAX=-M;cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i],MAX=max(MAX,a[i]),f[a[i]]+=1;
    int res=1;
    for (int i=1; i<=MAX; i++)
    {
        int dem=0;
        for (int j=i; j<=MAX; j+=i)
        {
            dem+=f[j];
            if (dem>=2)
            {
                res=max(res,i);
                break;
            }
        }
    }
    cout << res;
    return 0;
}
