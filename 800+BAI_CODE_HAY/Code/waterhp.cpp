#include <bits/stdc++.h>
using namespace std;
#define int long long 

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	string s; cin >> s;
	int H=0,O=0;
	for (char c : s)
	{
		H+=(c=='H');
		O+=(c=='O');
	}
	cout << min(H/2,O);
}