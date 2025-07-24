#include <bits/stdc++.h>
using namespace std;
int a[200005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
    while (q--)
    {
        int l, r; cin >> l >> r;
        if ((r - l + 1) & 1) cout << 1;
        else
        {
            int pos = l + (r - l + 1)/2 - 1;
            cout << a[pos + 1] - a[pos] + 1;
        }
        cout << '\n';
    }
}
