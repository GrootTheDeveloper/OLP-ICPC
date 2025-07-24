#include <bits/stdc++.h>
using namespace std;
#define int long long
int f[100005];
const int MAX=1e7;
bool prime[MAX+1];
void sie()
{
    int lim=trunc(sqrt(MAX));
    prime[1]=prime[0]=true;
    for (int i=2;i<=lim;i++) if (!prime[i])
    for (int j=i*i;j<=MAX;j+=i) prime[j]=true;
}
bool check(int n)
{
    int x=n;
    while (!prime[x]) x/=10;
    if (x) return false;
    for (int i=1;i<=9;i+=2)
    if (!prime[n*10+i]) return true;
    return false;
}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    sie();
    int n; cin >> n;
    int x=0;
    for (int i=1;i<=n;i++)
    {
        cin >> x;
        f[i]=f[i-1]+check(x);
    }
    int m,u,v; cin >> m;
    while(m--)
    {
        cin >> u >> v;
        cout << f[v]-f[u-1] << '\n';
    }

}
