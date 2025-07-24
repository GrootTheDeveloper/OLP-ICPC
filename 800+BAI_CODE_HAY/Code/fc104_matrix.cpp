#include <bits/stdc++.h>
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int x, y;
    for (int i = 1; i <= 5; i++)
    for (int j = 1; j <= 5; j++)
    {
        int ai; cin >> ai;
        if (ai) x = i, y = j;
    }
    cout << abs(x - 3) + abs(y - 3);
}
