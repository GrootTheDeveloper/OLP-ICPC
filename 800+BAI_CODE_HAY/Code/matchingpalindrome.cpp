#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int base = 311;
const int mode = 1e9 + 7;
string s;
int n,T[200006],p[200006],R[200006];
void Hash()
{
	T[0]=0;
	for (int i = 1; i <= s.size(); ++i)
		T[i] = (T[i-1]*base + s[i-1] - 'a') % mode;
	R[2*n]=0;
	for (int i = 2*n; i>=1; i--)
		R[i]= (R[i+1]*base + s[i-1] - 'a') % mode;
}
int gethash1(int l, int r)
{
	return (T[r]-T[l-1]*p[r-l+1]+mode*mode)%mode;
}
int gethash2(int l, int r)
{
	return (R[l]-R[r+1]*p[r-l+1]+mode*mode)%mode;
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	p[0] = 1;
	for (int i = 1; i <= 2e5; ++i) p[i] = p[i-1] * base % mode;
	for (int l = 1; l <= t; l++)
	{
		cin >> n;
		cin >> s;
		s = s + s;
		Hash();
		s = "#" + s;
		int pos = 2 * n;
		for (int i = 2 * n; i >= n+1; i--)
		{
			int mid = i/2;
			if (gethash1(1,mid) == gethash2(mid + 1 + (i&1), i)) pos = i;
		}
		cout << "Case #" << l << ": "; 
		for (int i = n+1; i <= pos; ++i) cout << s[i];
		cout << '\n';
	}
}