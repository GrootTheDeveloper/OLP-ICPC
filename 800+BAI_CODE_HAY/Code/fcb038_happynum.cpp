#include <bits/stdc++.h>
using namespace std;
#define int long long

string solve(int n)
{
    unordered_map <int,int> f;
    f[n]=1;
    while (true)
    {
        int res=0;
        while (n) res+=(n%10)*(n%10), n/=10;
        n=res;
        if (n==1) return "YES";
        if (f[n]) break;
        f[n]=1;
    }
    return "NO";
}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        cout << solve(n) << endl;
    }
}
