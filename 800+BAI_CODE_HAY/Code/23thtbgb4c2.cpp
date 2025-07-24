#include <bits/stdc++.h>
using namespace std;
#define maxn 500005
#define ma 10000007
#define mode 1000000007
int a[maxn],b[maxn],ta[ma],tb[ma],d[ma];

long long pow(int a, int b)
{
    if (b==0) return 1;
    long long x=pow(a, b/2);
    if (b%2==0) return x*x%mode;
    return x*x%mode*a%mode;
}
void xuli(int a[],int x)
{
    while (x>1)
    {
        int p=d[x];
        ++a[p];
        x/=p;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,k,MAX=INT_MIN;
    cin >> n >> m;
    for (int i=1; i<=n; i++)
    {
        cin >> a[i];
        MAX=max(a[i],MAX);
    }
    for (int i=1; i<=m; i++)
    {
        cin >> b[i];
        MAX=max(b[i],MAX);
    }
    for (int i=2; i<=MAX; i++)
    {
        if (d[i]) continue;
        for (int j=i; j<=MAX; j+=i)
            d[j]=i;
    }
    for (int i=1; i<=n; i++)
        xuli(ta,a[i]);
    for (int i=1;i<=m; i++)
        xuli(tb,b[i]);
    long long ans=1;
    for (int i=2; i<=MAX; i++)
    {
        ans=ans*(pow(i,min(ta[i],tb[i])))%mode;
    }
    cout << ans;

}
