#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,m,k,x,y;
unordered_map <int,bool> cot,hang;

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin >> n >> m >> k;
	int h=n,c=m;
	while (k--)
	{
		cin >> x >> y;
		h-=(hang[x]==false);
		c-=(cot[y]==false);
		hang[x]=cot[y]=true;
	}
	cout << h*c;
}