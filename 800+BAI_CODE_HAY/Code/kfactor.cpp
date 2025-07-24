#include <bits/stdc++.h>
using namespace std;
#define int long long 

int a,b,k;
int maxdiv[1000006];
int prime[100005];
vector <int> p;
void sie(int lim)
{
	for (int i = 2; i <= lim; i++)
		if (!prime[i])
		{
			p.push_back(i);
			for (int j = i * i; j <= lim; j += i) prime[j] = true;
		}
}

void sub1()
{
	for (int i = 2; i <= b; i++)
		if (!maxdiv[i]) for (int j = i; j <= b; j+=i) maxdiv[j] = i;
	int res = 0;
	for (int i = a; i <= b; i++) res += (maxdiv[i] <= k);
	cout << res;
}
int nxt(int &a, int &b)
{
	return a * (b/a + (b % a != 0));
}
int f[2000006];
void sub2()
{
	sie(k);
	for (int i = a; i <= b; i++) f[i - a + 1] = i;
	for (int c : p)
		for (int i = nxt(c, a); i <= b; i += c) 
			while (f[i - a + 1] % c == 0) f[i - a + 1] /= c;	
	int res = 0;
	for (int x = a; x <= b; x++)
		res += (f[x - a + 1] <= k);
	cout << res;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> k >> a >> b;
	if (b <= 1e6) sub1();
	else sub2();
	//cout << '\n' << clock() / (double)1000 << " sec";
}