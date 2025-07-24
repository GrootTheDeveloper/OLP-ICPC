#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int,int>
#define val first
#define idx second
//////////////////////////////////////////
const int SIZE = 3e5 + 5;
//////////////////////////////////////////
int seg[SIZE*4],n;
//////////////////////////////////////////
bool cmp(ii a, ii b)
{
	return ((a.val == b.val)? a.idx < b.idx : a.val > b.val);
}
ii a[SIZE];
///////////////////////////////////////////
void build(int id, int l, int r)
{
	if (l == r) return seg[id] = 1, void();
	int mid = (l + r) / 2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid +1, r);
	seg[id] = seg[id * 2] + seg[id * 2 + 1];
}
/////////////////////////////////////////////
void update(int id, int l, int r, int pos)
{
	if (pos > r || pos < l) return;
	if (l == r && pos == l) return seg[id] = 0, void();
	int mid = (l + r) / 2;
	update(id * 2, l, mid, pos);
	update(id * 2 + 1, mid + 1, r, pos);
	seg[id] = seg[id * 2] + seg[id * 2 +1];
}
/////////////////////////////////////////////
int get(int id, int l, int r, int u, int v)
{
	if (v < u) return 0;
	if (u > r || v < l) return 0;
	if (u <= l && r <= v) return seg[id];
	int mid = (l + r) / 2;
	return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid+1, r, u, v);
}
//////////////////////////////////////////////
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) 
	{
		cin >> a[i].val;
		a[i].idx = i;
	}
	sort(a + 1, a + n + 1, cmp);
	//for (int i = 1 ; i <= n; i++) cout << a[i].val << ' ' << a[i].idx << '\n';
	build(1,1,n);
	int pos = 1, res = 0;
	for (int i = 1; i <= n; i++)
	{
		ii x = a[i];
		if (x.val == a[i+1].val) 
		{
			update(1,1,n,x.idx);
			continue;
		}
		if (x.idx < pos)
		{
			res += get(1,1,n,pos,n) + get(1,1,n,1,x.idx-1);
			//cout << pos << ' ' << n << ';' << 1 << ' ' << x.idx -1 << ' ' << res << '\n';
		}
		else 
		{
			res += get(1, 1, n, pos, x.idx-1);
			//cout << pos << ' ' << x.idx -1 << ' ' << res <<  '\n';
		}
		//cout << pos << ' ' << x.idx << '\n';
		pos = x.idx;
		update(1, 1, n, pos);
	}
	cout << res;
}