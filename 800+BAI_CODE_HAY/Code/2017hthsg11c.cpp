#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
int a[1005];
bool f[1000005];
main()
{
    freopen("TRANSPORT.inp","r",stdin);
    freopen("TRANSPORT.out","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,s; cin >> n >> s;
    for (int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    f[0]=true;
    for (int i=1;i<=n;i++)
        if (a[i]<=s)
            for (int j=s;j>=a[i];j--)
                if (f[j-a[i]]) f[j]=true;
    s--;
    while (!f[s]) s--;
    cout << s;
}
