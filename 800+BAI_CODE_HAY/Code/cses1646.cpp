#include <bits/stdc++.h>
using namespace std;
#define int long long
int f[(int)2e5+5];
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,q,ai; cin >> n >> q;
    for (int i=1;i<=n;i++)
    {
        cin >> ai;
        f[i]=f[i-1]+ai;
    }
    int a,b;
    while (q--)
    {
        cin >> a >> b;
        cout << f[b]-f[a-1] << "\n";
    }
}
