#include <bits/stdc++.h>
using namespace std;
mt19937_64 rd(time(NULL));
int n, a[444][444], max_value = -1000;
void input(){
	cin >> n;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
		cin >> a[i][j], max_value = max(max_value, a[i][j]);
}
int solve1(){
	int ans = -1e9;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
	{
		int max_step = min({i - 1, n - i, n - j, j - 1});
		int cur_ans = 0;
		int x1, x2, y1, y2;
		x1 = x2 = i, y1 = y2 = j;
		for (int _ = 1; _ <= max_step; _++){
			x1--, x2++, y1--, y2++;
			cur_ans += a[x1][y1] - a[x1][y2] - a[x2][y1] + a[x2][y2];
			ans = max(ans, cur_ans);
		}
		
	}
	return ans;
}
int solve2(){
	int ans = -1e9;
	for (int i = 1; i < n; i++)
	for (int j = 1; j < n; j++)
	{
		int max_step = min({i - 1, n - i - 1, n - j - 1, j - 1});
		int cur_ans = a[i][j] - a[i + 1][j] - a[i][j + 1] + a[i + 1][j + 1];
		ans = max(ans, cur_ans);
		int x1 = i, x2 = i + 1, y1 = j, y2 = j + 1;
		for (int _ = 1; _ <= max_step; _++){
			x1--, x2++, y1--, y2++;
			cur_ans += a[x1][y1] - a[x1][y2] - a[x2][y1] + a[x2][y2];
			ans = max(ans, cur_ans);
		}
	}
	return ans;
}
int Rand(int L, int R){
	return L + rd() % (R - L + 1);
}
void gen(){
	n = Rand(100, 150);
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
		a[i][j] = Rand(-1000, 1000);
}
int buff()
{
	int ans = -1e9;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
	{
		int step = min(n - i + 1, n - j + 1);
		int x = i - 1, y = j - 1;
		int A = 0;
		while (step--)
		{
			x++, y++;
			A += a[x][y];
			int B = 0;
			int u = i, v = y;
			while (u <= x)
				B += a[u++][v--];
			ans = max(ans, A - B);
		}
	}
	return ans;
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	cout << max({solve1(), solve2(), 0});
	// freopen("test.inp","w",stdout);
	// srand(time(NULL));
	// int T = 200;
	// while (T--)
	// {
	// 	gen();
	// 	int A = max(solve1(), solve2()), B = buff();
	// 	if (A == B) cout << "ACCEPTED!\n";
	// 	else
	// 	{
	// 		cout << n << '\n';
	// 		for (int i = 1; i <= n; i++)
	// 		{
	// 			for (int j = 1; j <= n; j++)
	// 				cout << a[i][j] << ' ';
	// 			cout << '\n';
	// 		}
	// 		cout << "ANS : " << A << ' ' << B << '\n';
	// 	}
	// }	
}