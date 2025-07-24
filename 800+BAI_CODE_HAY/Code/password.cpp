#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<string, int>
#define txt first
#define id second

unordered_map <string, int> f;
int ans[10005];
ii a[10005];

bool cmp(ii a, ii b)
{
    return (a.txt.size() == b.txt.size()? a.txt < b.txt : a.txt.size() < b.txt.size());
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].txt, a[i].id = i;
    sort(a + 1, a + n + 1, cmp);


    for (int i = 1; i <= n; i++) cout << ans[i] - 1 << '\n';
}
