#include <bits/stdc++.h>
using namespace std;
#define int long long 


signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	string s; cin >> s;
	s.push_back('+');
	string st="";
	vector <int> v;
	for (char &c : s)
	{
		if (c=='+') v.push_back(stoll(st)),st="";
		else st.push_back(c);
	}
	sort(v.begin(),v.end());
	for (int i=0;i<v.size()-1;i++) cout << v[i] << '+';
	cout << v.back();
}