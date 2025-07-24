#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second 

ii lef[1000006], rig[1000006];
int a[1000006];
int n;
void build_lef(int n)
{
	for (int i = 1; i <= n; i++)
		lef[i] = make_pair(-1e10, 0);
	int cur = a[1], count_cur = 1;
	for (int i = 2; i <= n; i++)
	{
		if (cur - a[i] >= lef[i - 1].fi)
			lef[i] = make_pair(cur - a[i], (cur - a[i] == lef[i - 1].fi? lef[i - 1].se + count_cur : count_cur));
		else
			lef[i] = lef[i - 1];
		
		if (a[i] >= cur)
		{
			count_cur = (cur == a[i]? count_cur + 1 : 1);
			cur = a[i];
		}
	}
}
void build_rig(int n)
{
	for (int i = 1; i <= n; i++)
		rig[i] = make_pair(-1e10, 0);
	int cur = a[n], count_cur = 1;
	for (int i = n - 1; i >= 1; i--)
	{
		if (cur - a[i] >= rig[i + 1].fi)
			rig[i] = make_pair(cur - a[i], (cur - a[i] == rig[i + 1].fi? rig[i + 1].se + count_cur : count_cur));
		else 
			rig[i] = rig[i + 1];
	
		if (a[i] >= cur)
		{
			count_cur = (cur == a[i]? count_cur + 1 : 1);
			cur = a[i];
		}
	}
}
string int128_to_string(__int128 num) {
    if (num == 0) return "0";

    bool negative = num < 0;
    if (negative) num = -num;

    std::string result;
    while (num > 0) {
        result += '0' + (num % 10);
        num /= 10;
    }
    
    if (negative) result += '-';
    std::reverse(result.begin(), result.end());
    return result;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	build_lef(n);
	build_rig(n);

	int ans = -1e15	;
	__int128 cnt = 0;
	for (int i = 3; i <= n - 2; i++)
	{
		int tmp = a[i] + lef[i - 1].fi + rig[i + 1].fi;
		if (tmp >= ans)
		{
			cnt = (ans == tmp? cnt + (__int128)lef[i - 1].se * rig[i + 1].se : (__int128)lef[i - 1].se * rig[i + 1].se);
			ans = tmp;
		}
	}
	cout << ans << ' ' << int128_to_string(cnt);
	
}
