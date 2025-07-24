#include <bits/stdc++.h>
using namespace std;
#define int __int128 

struct node
{
	int a, b;

	node friend operator + (node &x, node &y)
	{
		int T = x.a * y.b + y.a * x.b;
		int M = x.b * y.b;
		int gcd = __gcd(T, M);
		return (node){T / gcd, M / gcd};
	}
	node friend operator * (node &x, node &y)
	{
		int T = x.a * y.a, M = x.b * y.b;
		int gcd = __gcd(T, M);
		return (node){T / gcd, M / gcd};
	}

	node friend operator / (node &x, node &y)
	{
		int T = x.a * y.b, M = x.b * y.a;
		int gcd = __gcd(T, M);
		return (node){T / gcd, M / gcd};
	}

	node friend operator - (node &x, node &y)
	{
		int T = x.a * y.b - y.a * x.b;
		int M = x.b * y.b;
		int gcd = __gcd(T, M);
		return (node){T / gcd, M / gcd};
	}
};

node extract(string s)
{
	signed pos = 0;
	signed a = 0, b = 0;
	while (s[pos] != '/')
	{
		a = a * 10 + s[pos] - '0';
		pos++;
	}
	pos++;
	while (pos < s.size())
		b = b * 10 + s[pos] - '0', pos++;
	return (node){a, b};
}

std::string to_string(__int128 x) {
    if (x == 0) return "0";
    bool isNegative = x < 0;
    if (isNegative) x = -x;
    std::string result;
    while (x > 0) {
        result += '0' + (x % 10);
        x /= 10;
    }
    if (isNegative) result += '-';
    std::reverse(result.begin(), result.end());
    return result;
}

// Hàm in __int128
std::ostream& operator<<(std::ostream& os, __int128 x) {
    return os << to_string(x);
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long n; cin >> n;
	node ans = {0, 1};
	while (n--)
	{
		char kind;
		string s;
		cin >> kind >> s;
		node X = extract(s);
		if (kind == '+')
			ans = ans + X;
		if (kind == '-')
			ans = ans - X;
		if (kind == '*')
			ans = ans * X;
		if (kind == '/')
			ans = ans / X;
	}
	cout << ans.a << '/' << ans.b;
}