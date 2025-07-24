#include <bits/stdc++.h>
using namespace std;
unordered_map <char,int> f;
int cnt;
void add(char c) {f[c]++,cnt+=(f[c]==1);}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	string s; cin >> s;
	int k; cin >> k;
	for (char i : s) add(i);
	if (cnt>=k) return cout << 0,0;
	if (s.size()-cnt<k-cnt) return cout << "impossible",0;
	cout << k-cnt;
	return 0;
	

}