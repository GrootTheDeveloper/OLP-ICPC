#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100005];
const int mode=1e9;
int power(int a, int b)
{
    if (b==0) return 1;
    if (b==1) return a;
    int x=power(a,b/2);
    if (b%2==0) return x*x%mode;
    return x*x%mode*a%mode;
}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen ("MUL.INP","r",stdin);
    freopen ("MUL.OUT","w",stdout);
    int n; cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    int b,res=0;
    for (int i=1;i<=n;i++)
    {
        cin >> b;
        res+=power(a[i],b)%mode;
    }
    cout << res % mode;
}
