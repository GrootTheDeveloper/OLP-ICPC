#include <bits/stdc++.h>
using namespace std;
#define int long long 

int layer[60], pre[60];
void init()
{
	layer[1] = 1;
	pre[1]   = 1;
	for (int i = 2; i <= 55; i++)
		layer[i] = layer[i - 1] * 2, pre[i] = pre[i - 1] + layer[i];
}

int face(int pos, int lay)
{
	if (pos & 1)
	{
		int tmp = pos / 2 + 1;
		return pre[lay - 1] + tmp - 1;
	}
	int tmp = pos / 2;
	return pre[lay - 1] + layer[lay] / 2 + tmp - 1;
}
int Pos(int id, int lay)
{
	if (id == 0) return 1;
	if (id <= pre[lay - 1] + layer[lay] / 2 - 1)
	{
		int tmp = id - (pre[lay - 1] - 1);
		return tmp * 2 - 1;
	}
	int tmp = id - (pre[lay - 1] + layer[lay] / 2 - 1);
	return tmp * 2;

}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	init();
	int n; cin >> n;
	int lay = lower_bound(pre + 1, pre + 55, n + 1	) - pre;

	int pos = Pos(n, lay);
	cout << face(pos / 2 + (pos & 1), lay - 1) << '\n';
	cout << face(pos * 2 - 1, lay + 1) << ' ' << face(pos * 2, lay + 1);

}