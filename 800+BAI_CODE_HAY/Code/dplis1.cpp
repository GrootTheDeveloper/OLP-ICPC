#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
struct input
{
	int val, id;
	bool operator < (const input &other) const
	{
		return (val == other.val? id < other.id : val < other.val);
	}
}a[100005];
long long bit[N + 5];
void update(int idx, long long val)
{
	for (; idx <= N; idx += idx & -idx)
		bit[idx] = max(bit[idx], val);
}
long long get(int idx)
{
	long long ans = 0;
	for (; idx; idx -= idx & -idx)
		ans = max(ans, bit[idx]);
	return ans;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].val, a[i].id = i;

	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		update(a[i].id, get(a[i].id - 1) + a[i].val);
	cout << get(n);

}