#include <bits/stdc++.h>
using namespace std;
#define int long long
unordered_map <int,int> f;

main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    freopen("DANCE.INP","r",stdin);
    freopen("DANCE.OUT","w",stdout);
    int n; cin >> n;
    string s; cin >> s;
    int sum=0,res=0;
    for (char c : s)
    {
        sum+=(c=='a')? 1:-1;
        res+=(sum==0);
        res+=f[sum];
        f[sum]++;
    }
    cout << res;
}
