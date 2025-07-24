#include <bits/stdc++.h>
using namespace std;
multiset <int> s;
multiset <int> :: iterator it;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    for (int i=1;i<=n;i++)
    {
        int ai; cin >> ai;
        s.insert(ai);
        it=s.lower_bound(ai);
        it++;
        if (it!=s.end()) s.erase(it);

    }
    cout << s.size();
}
