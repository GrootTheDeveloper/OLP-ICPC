#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> s;
	while ((int)s.size()) cout << s.back(),s.pop_back();

}