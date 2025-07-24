#include <bits/stdc++.h>
using namespace std;
#define int long long
int l,r;
int calc(int l, int r)
{
	return r*(r+1)/2-(l-1)*l/2;
}

void sub1()
{
	int delta=INT_MAX,res=l;
	for (int i=l;i<r;i++)
	{
		int x=calc(l,i),y=calc(i+1,r);
		if (delta>abs(x-y)) delta=abs(x-y),res=i;

	}
	cout << res;
}
void sub2()
{
	
}

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin >> l >> r;
	if (r<=1e6) sub1();
	else sub2();
}