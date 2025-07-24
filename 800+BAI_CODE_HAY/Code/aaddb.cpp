#include <bits/stdc++.h>
using namespace std;
#define int long long 

struct big{
	string num;

	string operator + (const big& other) const
	{
		string a = num;
		string b = other.num;
		while (a.size() < b.size()) a = "0" + a;
		while (a.size() > b.size()) b = "0" + b;
		int nho = 0;
		string res = "";
		for (int i = a.size() - 1, k; i >= 0; i--)
		{
			k = (a[i] - '0') + nho + (b[i] - '0');
			nho = k / 10;
			res = to_string(k % 10) + res;
		}
		if (nho) res = to_string(nho) + res;
		return res;
	}
};

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	big a,b; cin >> a.num >> b.num;
	cout << a + b;
}