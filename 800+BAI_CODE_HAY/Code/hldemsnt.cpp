#include <bits/stdc++.h>
using namespace std;
int f[1000006],n,l,r;
bool prime[1000006];

void sie()
{
    prime[1]=true;
    int N=1000;
    for (int i=2;i<=N;i++)
        if (!prime[i]) for (int j=i*i;j<=1e6;j+=i) prime[j]=true;
    for (int i=1;i<=1e6;i++) f[i]=f[i-1]+(!prime[i]);
}

main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen("demsnt.inp","r",stdin);
    freopen("demsnt.out","w",stdout);
    int q; cin >> q;
    sie();
    while (q--)
    {
        cin >> l >> r;
        cout << f[r]-f[l-1] << '\n';
    }
}
