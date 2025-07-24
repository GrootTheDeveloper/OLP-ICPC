#include <bits/stdc++.h>
using namespace std;
#define int long long 


main()
{
	string s; getline(cin,s);
	while (s.back()==' ') s.pop_back();
	string st="";
	while (s.back()!=' ') st.push_back(s.back()),s.pop_back();
	for (int i=st.size()-1;i>=0;i--) cout << st[i];
}