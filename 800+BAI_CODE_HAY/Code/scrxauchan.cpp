#include <bits/stdc++.h>
using namespace std;
int cnt,f[256];
void add(char c) { f[c-'0']++, cnt+=((f[c-'0']&1)?1:-1);}

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	string s; cin >> s;
	for (char c: s) add(c);
	cout << ((cnt)?"No":"Yes");
}