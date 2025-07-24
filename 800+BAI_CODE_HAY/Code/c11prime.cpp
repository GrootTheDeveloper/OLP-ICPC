#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
int n;
bool nto(int n)
{
	if (n<2) return 0;
	int lim=trunc(sqrt(n));
	for (int i=2;i<=lim;i++) if (n%i==0) return 0;
	return 1;
}
bool prime[42002];
vector <int> p;
void sie()
{
	for (int i=2;i<=42000;i++)
	if (!prime[i]){
		p.push_back(i);
		for (int j=i*i;j<=42000;j+=i) prime[j]=true;
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n;
	sie();
	int s1=trunc(sqrt(n)),s2=trunc(cbrt(n));
	if (s1*s1==n && nto(s1)) return cout << s1 << ' ' << 2,0;
	if (s2*s2*s2==n && nto(s2)) return cout << s2 << ' ' << 3,0;
	for (int c : p)
	{
		if (c==n) return cout << 0,0;
		int k=c,q=1;
		while (n/k>=c) k*=c,q++;
		if (k==n) return cout << c << ' ' << q,0;
	}
	cout << 0;

}