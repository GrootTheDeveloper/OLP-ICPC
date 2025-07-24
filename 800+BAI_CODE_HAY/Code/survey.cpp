#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[55], b[55];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int idx = 1;
    for (int i = 2; i <= n; i++)
        if (a[idx] * b[i] < a[i] * b[idx]) idx = i;
    cout << 1 << '\n' << idx;
}
