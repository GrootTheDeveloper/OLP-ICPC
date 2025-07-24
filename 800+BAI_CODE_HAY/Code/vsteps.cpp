#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode=14062008;
bool los[100005];
int f[100005];
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,k,ai; cin >> n >> k;
    for (int i=1;i<=k;i++)
    {
        cin >> ai;
        los[ai]=true;
    }
    f[1]=1;
    for (int i=2;i<=n;i++)
        if (!los[i]) f[i]=(f[i-1]+f[i-2])%mode;
    cout << f[n];
}
