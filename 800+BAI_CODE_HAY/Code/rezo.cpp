#include <bits/stdc++.h>
using namespace std;
#define int long long
unordered_map <int, int> f;

main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    int s=0,ai,res=0;
    for (int i=1;i<=n;i++)
    {
        cin >> ai;
        s+=ai;
        if (s==0) res++;
        res+=f[s];
        f[s]++;

    }
    cout << res;
}
