#include <bits/stdc++.h>
using namespace std;
struct node{
    vector<int> index;
};
node f[(int)1e6+7];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,q; cin >> n >> q;
    for (int i=1;i<=n;i++)
    {
        int ai;
        cin >> ai;
        f[ai].index.push_back(i);
    }
    while (q--)
    {
        int x,l,r;
        cin >> x >> l >> r;
        if (f[x].index.size()==0)
        {
            cout << 0 << endl;
            continue;
        }
        auto it1=lower_bound(f[x].index.begin(),f[x].index.end(),l);
        auto it2=upper_bound(f[x].index.begin(),f[x].index.end(),r);
        cout << it2-it1 << endl;
    }
}
