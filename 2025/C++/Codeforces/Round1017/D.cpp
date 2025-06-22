#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while(t--) {
        string p, s;
        cin >> p >> s;
        int n = p.size();
        int m = s.size();

        vector<string>a;
        vector<string>b;
        string temp;

        temp += p[0];
        for (int i = 1; i < n; i++) {
            if (p[i] != p[i - 1]) {
                a.push_back(temp);
                temp.clear();
                temp += p[i];
            }
            else {
                temp+=p[i];
            }            
        }
        if (!temp.empty()) {
            a.push_back(temp);
        }

        temp.clear();
        temp+=s[0];

        for (int i = 1; i < m; i++) {
            if (s[i] != s[i - 1]) {
                b.push_back(temp);
                temp.clear();
                temp += s[i];
            }
            else {
                temp+=s[i];
            }            
        }
        if (!temp.empty()) {
            b.push_back(temp);
        }

        bool check = true;
        if (a.size() != b.size()) {
            check = false;
        }
        else {
            for (int i = 0; i < a.size(); i++) {
                if (a[i][0] != b[i][0]) {
                    check = false;
                    break;
                }
                if (a[i].size() <= b[i].size() && a[i].size() * 2 >= b[i].size()) {
                    continue;
                }
                else {
                    check = false;
                    break;
                }
            }
        }
        if (check) cout << "YES";else cout << "NO";
		cout << endl;
	}
}