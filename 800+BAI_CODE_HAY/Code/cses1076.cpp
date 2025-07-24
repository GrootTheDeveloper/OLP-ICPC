#include <bits/stdc++.h>
using namespace std;
//#define int long long 
struct Segmentree
{
	vector <int> sum, cnt;
	int n;
	Segmentree (int _n)
	{
		n = _n;
		cnt.assign(n * 4 + 5, 0);
	}
	void update(int id, int l, int r, const int &pos, int heso)
	{
		if (pos > r || pos < l) return;
		if (l == r && pos == l)
		{
			//sum[id] += pos * heso;
			cnt[id] += heso;
			return;
		}
		int mid = (l + r) >> 1;
		update(id * 2, l, mid, pos, heso);
		update(id * 2 + 1, mid + 1, r, pos, heso);
		//sum[id] = sum[id << 1] + sum[id << 1 | 1];
		cnt[id] = cnt[id << 1] + cnt[id << 1 | 1];
	}

	int calc(int id, int l, int r, int pos)
	{
		if (l > pos) return 0;
		if (r <= pos) return cnt[id];
		int mid = (l + r) >> 1;
		return calc(id << 1, l, mid, pos) + calc(id << 1 | 1, mid + 1, r, pos);
	}
	int calc(int pos)
	{return calc(1, 1, n, pos);}
	void update(const int &pos, int heso)
	{update(1, 1, n, pos, heso);}
	
	int get(int k)
	{
		int ans = 0;
		int l = 1, r = n;
		k = k / 2 + (k&1);
		while (l <= r)
		{
			int mid = (l + r) >> 1;
			if (calc(mid) >= k) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		return ans;
	}
};
unordered_map <int, int> zip;
int unzip[200005], a[200005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	set <int> s;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		s.insert(a[i]);
	}
	int lim = 0;
	for (int val : s)
	{
		unzip[++lim] = val;
		zip[val] = lim;
	}
	Segmentree ST(lim + 1);
	for (int i = 1; i <= n; i++)
	{
		ST.update(zip[a[i]], 1);
		if (i >= k)
		{
			cout << unzip[ST.get(k)] << ' ';
			ST.update(zip[a[i - k + 1]], -1);
		}
	}	
} 