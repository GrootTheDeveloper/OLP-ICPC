#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int q; cin >> q;
    while (q--)
    {
        int a,b; cin >> a >> b;
        bitset <15> s1(a), s2(b);
        bitset <15> s;
        for (int i = 0; i <= 4; i++) s[i] = s1[i]|s2[i];
        for (int i = 5; i <= 9; i++) s[i] = s1[i]&s2[i];
        for (int i = 10; i <= 14; i++) s[i] = s1[i]^s2[i];
        cout << s.to_ullong() << '\n';
    }
}
