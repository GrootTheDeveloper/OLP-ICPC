#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    bitset <32> s;
    int q; cin >> q;
    while (q--)
    {
        int kind, pos;
        cin >> kind >> pos;
        if (kind == 1) s.set(pos);
        if (kind == 2) s.reset(pos);
        if (kind == 3) s.flip(pos);
        cout << s.to_ullong() << '\n';
    }
}
