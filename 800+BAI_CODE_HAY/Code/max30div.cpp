#include <bits/stdc++.h>
using namespace std;
#define int long long 

int cnt[10];
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	int sum = 0;
	for (int i = 1,val; i <= n; i++)
	{
		cin >> val;
		cnt[val]++;
		sum += val;
	}
	if (cnt[0]==0) return cout << -1,0;
	n-=cnt[0];
	bool dec = (sum % 3 == 0);

	if (dec == false)
	{
		for (int i = 1; i <= 9; i++)
			if (cnt[i] && (sum - i) % 3 ==0) {cnt[i]--; dec = true; n--; break;}
		for (int i = 1; i < 9 && !dec; ++i)
				if ((sum - 2*i) % 3 == 0 && cnt[i] > 1) n -= 2, dec = true, cnt[i] -= 2; 
		for (int i = 1; i < 9 && !dec; i++)
			for (int j = i + 1; j < 9 && !dec; j++)
			 	if (cnt[i] && cnt[j] && (sum-i-j)% 3 == 0) n -= 2, dec = true, cnt[i]--, cnt[j]--; 
	}
	if (n==0) return cout << 0,0;
	for (int i = 9; i >= 0; i--)
		while (cnt[i]) cout << i, cnt[i]--;
}