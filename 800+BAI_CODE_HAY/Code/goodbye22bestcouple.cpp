#include <bits/stdc++.h>
using namespace std;
unordered_map<int,int> f;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,res=0; cin >> n;
    while (n--)
    {
        int ai;
        cin >> ai;
        res+=f[ai];
        f[ai]++;
    }
    return cout << res,0;
}
