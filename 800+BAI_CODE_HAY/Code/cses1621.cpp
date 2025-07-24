#include <bits/stdc++.h>
using namespace std;
unordered_map <int , int> f;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,res=0; cin >> n;
    for (int i=1; i<=n; i++)
    {
        int ai;
        cin >> ai;
        f[ai]++;
        if (f[ai]==1) res++;
    }
    cout << res;
    return 0;
}
