#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
bool prime[N],ft[N];
void siuuu()
{
    ft[1]=true;
    for (int i=2;i<=N;i++)
    {
        if (!prime[i])
        {
            ft[i]=true;
            for (int j=i*i;j<=N;j+=i)
                prime[j]=true;
        }
        else
            for (int j=i*2;j<=N;j+=i)
                ft[j]=true;
    }
}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    siuuu();
    int res=0;
    while (n--)
    {
        int ai; cin >> ai;
        res+=!ft[ai];

    }
    cout << res;
}
