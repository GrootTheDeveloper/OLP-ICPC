#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000007], n, q, l ,r,f[1000007] ;
main()
{
    cin >> n >> q;
    for (int i=1; i<=n; i++)
        {
            cin >> a[i];
            f[i]=f[i-1]+a[i];
        }
    while (q--)
    {
        cin >> l >> r;
        cout << f[r]-f[l-1] << '\n';

    }



}