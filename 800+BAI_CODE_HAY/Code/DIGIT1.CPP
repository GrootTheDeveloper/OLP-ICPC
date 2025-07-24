#include <bits/stdc++.h>
using namespace std;
int cnt_num[1000006][10];
void init()
{
	for (int i = 1; i <= 1e6; i++)
	{
		for (int j = 0; j <= 9; j++)
			cnt_num[i][j] = cnt_num[i - 1][j];
		int num = i;
		while (num) cnt_num[i][num % 10]++, num /= 10;
	}
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int num_case; cin >> num_case;
	init();
	while (num_case--)
	{
		int num; cin >> num;
		for (int i = 0; i <= 9; i++)
			cout << cnt_num[num][i] << ' ';
		cout << '\n';
	}
}