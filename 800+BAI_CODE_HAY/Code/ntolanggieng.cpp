//https://codeforces.com/gym/512327/problem/B
#include <bits/stdc++.h>
using namespace std;
#define int long long
int x,f[1000006];
bool prime[1000006];
void sie()
{
    for (int i=2;i<=1000;i++)
    if (!prime[i]) for (int j=i*i;j<=1e6;j+=i) prime[j]=true;
    for (int i=2;i<=1e6;i++)
        if (!prime[i]) f[i]=i;
        else f[i]=f[i-1];
}
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    sie();
    while (t--)
    {
        cin >> x;
        cout << f[x] << '\n';
    }
}
