#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
    int val, id;
    bool operator < (const node &other)
    {
        return (val == other.val? id < other.id : val < other.val);
    }
}a[1000005];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].val, a[i].id = i;
    sort(a + 1, a + n + 1);
    int s1 = a[n].val, s2 = s1 + a[s1].val;
    if (a[s2].val <= n - s2)
    {
        cout << s1 << ' ';for (int i = 1; i <= s1; i++) cout << a[i].id << ' ';
        cout << '\n';
        cout << s2 - s1 << ' '; for (int i = s1 + 1; i <= s2; i++) cout << a[i].id << ' ';
        return 0;
    }
    for (int s3 = 1; s3 <= n; s3++)
    {
        s2 = n - a[s3].val;
        if (a[n].val <= s2 - s3 && a[s2].val <= s3)
        {
            cout << n - s2 << ' '; for (int i = s2 + 1; i <= n; i++) cout << a[i].id << ' ';
            cout << '\n';
            cout << s2 - s3<< ' '; for (int i = s3 + 1; i <= s2; i++) cout << a[i].id << ' ';
            return 0;
        }
    }
    cout << -1;
}
