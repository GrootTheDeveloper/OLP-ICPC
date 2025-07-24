#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100005], dif, cnt[100005];

void add(int val) {dif += (++cnt[val] == 2);}
void del(int val) {dif -= (--cnt[val] == 1);}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int l = 1, res = 0;
    for (int i = 1; i <= n; i++)
    {
        add(a[i]);
        while (dif) del(a[l++]);
        res += i - l + 1;
    }
    cout << res;
}
