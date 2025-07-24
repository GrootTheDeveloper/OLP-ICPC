#include <bits/stdc++.h>
using namespace std;
#define int long long
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,sum=0,ai,res=0; cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> ai;
        sum+=ai;
        if (!ai) res+=sum;
    }
    cout << res;
}
