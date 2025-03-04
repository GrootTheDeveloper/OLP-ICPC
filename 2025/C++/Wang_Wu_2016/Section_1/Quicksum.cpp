#include <bits/stdc++.h>
using namespace std;
	
int main() {
	
	string s;
	while (getline(cin, s) && s != "#") {
		int ans = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ') continue;
			ans += (i + 1) * (s[i] - 'A' + 1);
		}
		cout << ans << endl;
	}

}