#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define val first
#define id second

ii a[100005];
int pre[100005];
int n, k, m;
void sub1()
{
    a[n + 1].val = 1e12;
    for (int i = 1; i <= n + 1; i++)
        pre[i] = pre[i - 1] + a[i].val;
    int pos;
    for (int i = 2; i <= n + 1; i++)
        if (a[i].val * i - pre[i] > m * k)
        {
            pos = i - 1;
            break;
        }

    int cur = m * k - (a[pos].val * pos - pre[pos]);
    int inc = cur / pos;
    int car = cur - inc * pos;
    for (int i = pos; i >= 1; i--)
        a[i].val = a[pos].val + inc;

    for (int i = pos; i >= pos - car + 1; i--)
        a[i].val++;
    for (int i = 1; i <= n; i++)
    cout << a[i].val << ' ';
}

void sub2()
{
    priority_queue <int, vector<int>, greater<int>> q;
    for (int i = 1; i <= n; i++)
        q.push(a[i].val);
    while (m--)
    {
        vector <int> vec;
        for (int i = 1; i <= k; i++)
        {
            vec.push_back(q.top() + 1);
            q.pop();
        }
        for (int c : vec) q.push(c);
    }
    while (q.size())
        cout << q.top() << ' ', q.pop();
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].val, a[i].id = i;
    cin >> m >> k;
    sort(a + 1, a + n + 1);
    if (k == 1) sub1();
    else sub2();

}
