#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[100005], len;
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;
    vector <int> vec;
    for (int i = a1; i <= b1; i++)
        for (int j = a2; j <= b2; j++)
            a[++len] = i + j;
    sort(a + 1, a + len + 1);
    int cur = 0;
    cin >> a1 >> b1 >> a2 >> b2;
    for (int i = a1; i <= b1; i++)
        for (int j = a2; j <= b2; j++)
        {
            int k = i + j;
            cur += lower_bound(a + 1, a + len + 1, k) - a - 1;
            cur -= len - (upper_bound(a + 1, a + len + 1, k) - a) + 1;
        }
    if (cur == 0) cout << 3;
    else if (cur > 0) cout << 2;
    else cout << 1;
}
