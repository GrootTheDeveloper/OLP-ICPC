#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100005],f[100005],q,x,y;
bool nt(int n)
{
    if (n<2) return 0;
    for (int i=2;i<=trunc(sqrt(n));i++) if (n%i==0) return 0;
    return 1;
}

bool check(int n)
{
    int x=n;
    while (nt(x)) x/=10;
    if (x) return false;
    bool t=0;
    for (int i=1;i<=9;i+=2) t=(t || nt(n*10+i));
    return t;
}

main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) f[i]=f[i-1]+check(a[i]);
    cin >> q;
    while (q--)
    {
        cin >> x >> y;
        cout << f[y]-f[x-1] << '\n';
    }
}
