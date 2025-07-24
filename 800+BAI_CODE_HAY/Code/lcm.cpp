#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mode = 1e9 + 7;

int f[1000006], gt[1000006], divs[1000006], COUNT, a, b; 
int power(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b&1) res = (res * a) % mode;
		a = (a * a) % mode;
		b >>= 1;
	}
	return res;
}

void init(int lim)
{
	for (int i = 2; i <= lim; i++)
		if (!divs[i]) for (int j = i; j <= lim; j += i) divs[j] = i;
	gt[0] = 1;
	for (int i = 1; i <= lim; i++) gt[i] = gt[i - 1] * i % mode;
}

void fun(int n)
{
	while (n != 1)
	{
		COUNT += (++f[divs[n]] == 1);
		n /= divs[n];
	}
}
int comb(int &k, int &n)
{
	return gt[n] * power(gt[k] * gt[n - k] % mode, mode - 2) % mode;
}
void counting_pair(int n)
{
	int rez = 1;
	for (int i = 2; i <= b; i++)
		if (f[i]) rez = (rez * (f[i] + 1)) % mode;
	int lag = 0;
	for (int i = 1; i < n; i++)
		lag += comb(i, n);
	cout << rez << ' ' << lag << ' ';
	int res = 0;
	res += lag * rez % mode;
	res -= lag + 1;
	res += rez;
	cout << (res + mode * mode) % mode;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> a >> b;
	init(b);
	for (int i = a; i <= b; i++) fun(i);
	counting_pair(COUNT);
}