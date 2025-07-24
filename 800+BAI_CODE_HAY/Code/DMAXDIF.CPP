#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 31 + 01 + 2007;
int n, m;
int a[N], b[N];


namespace sub1
{

	void work()
	{

		int ans = 0;
		for (int id1 = 1; id1 <= n; id1++)
		for (int id2 = 1; id2 <= n; id2++)
		{
			int max_ans_arrA = 0;
			for (int i = id1; i <= n; i++)
			{
				if (i > id1) max_ans_arrA = max(max_ans_arrA, abs(a[i] - a[i - 1]));
				int max_ans_arrB = 0;
				for (int j = id2; j <= n; j++)
				{
					if (j > id2) max_ans_arrB = max(max_ans_arrB, abs(b[j] - b[j - 1]));
					if (j - id2 + 1 + i - id1 + 1 == m) 
						ans = max({ans, max_ans_arrA, max_ans_arrB, abs(a[i] - b[id2])});
				}
			}
		}
		cout << ans << ' ';
	}
}

namespace sub2
{
		
	int maxB[N], minB[N];

	void work()
	{
		minB[0] = 1e9 + 31 + 01 + 2007;
		for (int i = 1; i <= n; i++)
		{
			maxB[i] = max(maxB[i - 1], b[i]);
			minB[i] = min(minB[i - 1], b[i]);
		}

		int ans = 0;
		for (int i = max(1, m - n); i <= n; i++)
		{
			int id = n - max(0, m - i - 1);
			ans = max(ans, max(abs(a[i] - maxB[id]), abs(a[i] - minB[id]))); 
			//cout << id << ' ' << ans << '\n';
		}
		for (int i = 1; i < n; i++)
		{
			ans = max(ans, abs(a[i] - a[i + 1]));
			ans = max(ans, abs(b[i] - b[i + 1]));
		}
		cout << ans;
	}
}
namespace sub4{
    int premx[300005];
    int premn[300005];
    int mx[1200005];
    int mn[1200005];
    void reset(int x){
        for (int i = 1; i <= x * 4; i ++){
            mx[i] = 0;
        }
    }
    void up(int x, int l, int r, int u, int chg){
        if (l > r || l > u || r < u) return;
        if (l == r){
            mx[x] = chg;
            return;
        }
        int mid = (l + r) / 2;
        up(x * 2, l, mid, u, chg);
        up(x * 2 + 1, mid + 1, r, u, chg);
        mx[x] = max(mx[x * 2], mx[x * 2 + 1]);
        return;
    }
    int re(int x, int l, int r, int u, int v){
        if (l > r || l > v || r < u) return -1e18;
        if (l >= u && r <= v){
            return mx[x];
        }
        int mid = (l + r) / 2;
        return max(re(x * 2, l, mid, u, v), re(x * 2 + 1, mid + 1, r, u, v));
    }
    void up_mn(int x, int l, int r, int u, int chg){
        if (l > r || l > u || r < u) return;
        if (l == r){
            mn[x] = chg;
            return;
        }
        int mid = (l + r) / 2;
        up_mn(x * 2, l, mid, u, chg);
        up_mn(x * 2 + 1, mid + 1, r, u, chg);
        mn[x] = min(mn[x * 2], mn[x * 2 + 1]);
        return;
    }
    int re_mn(int x, int l, int r, int u, int v){
        if (l > r || l > v || r < u) return 1e18;
        if (l >= u && r <= v) return mn[x];
        int mid = (l + r) / 2;
        return min(re_mn(x * 2, l, mid, u, v), re_mn(x * 2 + 1, mid + 1, r, u, v));
    }
    void solve(){
        int res = 0;
        if (m > 2){
            // case 1 : gia tri lon nhat cua D nam trong doan lien tiep A
            int l = 1;
            for (int i = 1; i <= n; i ++){
                while (l <= n && b[l] <= a[i]){
                    l ++;
                }
                up(1, 1, n, i, min(m - 1, (n - l + 1)) + min(m - 1, i));
            }
            for (int i = 2; i <= n; i ++){
                if ((re(1, 1, n, i, i + m - 3) ) >= m){
                    res = max(res, abs(a[i] - a[i - 1]));
                }
            }
            reset(n);
            l = 1;
            for (int i = 1; i <= n; i ++){
                while (l <= n && a[l] < b[i]) l ++;
                up(1, 1, n, i, min(m - 1, n - i + 1) + min(m - 1, l - 1));
            }
            for (int i = 2; i <= n; i ++){
                if (re(1, 1, n, i - m + 3, i - 1) >= m)res = max(res, abs(b[i] - b[i - 1]));
            }
        }
        reset(n);
        for (int i = 1; i <= n; i ++){
            up(1, 1, n, i, b[i]);
        }
        for (int i = 1; i <= n; i ++){
            up_mn(1, 1, n, i, b[i]);
        }
        // case 3: gias trij lon nhat cua D o vi tri dau cua B va vi tri cuoi cua A
        int l = 1;
        for (int i = 1; i <= n; i ++){
            int len = min(i, m - 1);
            while (l <= n && b[l] <= a[i]) l ++;
            if (n - m + 1 + len >= 1 && l <= min(n, n - m + 1 + len)){
                res = max({res, abs(re(1, 1, n, l, min(n, n - m + 1 + len)) - a[i]), abs(re_mn(1, 1, n, l, min(n, n - m + 1 + len)) - a[i])});
            }
        }
        cout <<  res << ' ';
    }
};
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.inp","r",stdin);
	freopen("output.out","w",stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	sub4::solve();
	sub2::work();

}