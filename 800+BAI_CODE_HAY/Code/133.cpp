#include <bits/stdc++.h>
using namespace std;
#define int long long

multiset <int> s;
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) s.insert(i);
    for (int i = 1; i <= n; i++)
    {
        int ai; cin >> ai;
        auto it = s.lower_bound(ai);
        if (it == s.end()) it = s.begin();
        cout << *it << ' ';
        s.erase(it);
    }
}
