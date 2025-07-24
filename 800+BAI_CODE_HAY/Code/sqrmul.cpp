#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode=1e9+7;
int a[100005],divs[10000007],f[10000007];
vector <int> v;
void sie(int lim)
{
    int m=(int)sqrt(lim);
    for (int i=2;i<=m;i++)
        if (!divs[i]) for (int j=i*i;j<=lim;j+=i) divs[j]=i;
    for (int i=2;i<=lim;i++) if (divs[i]==0) divs[i]=i;
}
void process(int n)
{
    int cnt=0,k;
    while (n!=1)
    {
        k=divs[n];
        while (n%k==0) n/=k,cnt++;
        if (f[k]==0) v.push_back(k);
        f[k]=max(f[k],cnt);
        cnt=0;
    }
}
int power(int a, int b)
{
    int res=1;
    while (b)
    {
        if (b&1) res=(res*a)%mode;
        a=(a*a)%mode;
        b/=2;
    }
    return res;
}
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    int mx=0;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
        mx=max(mx,a[i]);
    }
    sie(mx);
    for (int i=1;i<=n;i++) process(a[i]);
    int res=1;
    for (int c : v)
        res=(res*power(c,f[c]+(f[c]&1)))%mode;
    cout << res;
}