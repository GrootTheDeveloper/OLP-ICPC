#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode=1e9+7,base=311;
string s,s1,s2;
int h[1000006],power[1000006];

void init()
{
	power[0]=1;
	for (int i=1;i<s.size();i++) power[i]=(power[i-1]*base)%mode;
	for (int i=1;i<s.size();i++)
		h[i]=(h[i-1]*base + s[i] - 'a')%mode;
}
int gethash(int l, int r)
{
	return (h[r]-h[l-1]*power[r-l+1]+mode*mode)%mode;
}

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> s;
	s='#'+s;
	init();
	int l=1,r=s.size()-1;
	while (l<s.size()-1)
	{
		if (gethash(1,l)==gethash(r,s.size()-1)) cout << l << ' ';
		l++;
		r--;
	}
}