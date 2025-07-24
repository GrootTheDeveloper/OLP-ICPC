#include <bits/stdc++.h>
using namespace std;
#define MAX 1000002
#define int long long
bool prime[MAX];
main()
{
    freopen ("GOL.INP","r",stdin);
    freopen ("GOL.OUT","w",stdout);
    int n;
    cin >> n;
    for (int i=2;i*i<=n;i++)
        if (!prime[i])
        {

            for (int j=i*i;j<=n;j+=i)
                prime[j]=true;
        }
    int res=0;
    for (int i=2;i<=n/2;i++) if (prime[i]+prime[n-i]==0) res++;
    cout << res;
}

