#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+1;
int f[N],pre[N];
void sang()
{
    for (int i=2;i<=N;i++)
    {
        for (int j=i;j<=N;j+=i) f[j]++;
    }
    for (int i=1;i<=N;i++)
        pre[i]=1+pre[i-1]+f[i];
}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    sang();
    while (t--)
    {
        int l,r; cin >> l >> r;
        cout << pre[r]-pre[l-1] << '\n';
    }

}
