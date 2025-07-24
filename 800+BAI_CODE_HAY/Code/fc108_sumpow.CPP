#include <bits/stdc++.h>
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i <= 30; i++)
    if (n >> i & 1) cout << (1 << i) << ' ';
}
