#include <bits/stdc++.h>
using namespace std;
#define int long long
unordered_map <int , int> f;
main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,ai,k,temp=0,res=0; cin >> n >> k;
    for (int i=1;i<=n;i++)
    {
        cin >> ai;
        temp+=ai;
        if (temp==k) res++;
        res+=f[temp-k];
        f[temp]++;

    }
    cout << res;
}
