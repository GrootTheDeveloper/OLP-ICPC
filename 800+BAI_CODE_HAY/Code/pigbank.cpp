#include <bits/stdc++.h>
using namespace std;
const int MAX=2e5+5;
int d[MAX];
vector <int> f;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m; cin >> n >> m;
    while (m--)
    {
        int l,r; cin >> l >> r;
        d[l]++;
        d[r+1]--;
    }
    int x=0;
    for (int i=1;i<=n;i++)
    {
        x=(x+d[i]);
        f.push_back(x);
    }
    sort(f.begin(),f.end());
    int q; cin >> q;
    while (q--)
    {
         int k;
         cin >> k;
         auto it=lower_bound(f.begin(),f.end(),k);
         cout << f.end()-it << endl;
    }
    return 0;
}
