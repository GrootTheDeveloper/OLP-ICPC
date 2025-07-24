#include <bits/stdc++.h>
using namespace std;
vector <int> a;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen ("CLIMBSTAIR.INP","r",stdin);
    freopen ("CLIMBSTAIR.OUT","w",stdout);
    int n,m; cin >> n >> m;
    a.push_back(0);
    for (int i=1;i<=n;i++)
    {
        int ai; cin >> ai;
        a.push_back((ai>a.back())? ai:a.back());
    }
    while (m--)
    {
        int x; cin >> x;
        auto it=upper_bound(a.begin(),a.end(),x);
        cout << it-a.begin()-1 << endl;
    }


}
