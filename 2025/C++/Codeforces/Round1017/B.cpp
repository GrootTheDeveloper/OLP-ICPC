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
        int i = 0, j = 0;
        bool check = true;
        int can_l = 0, can_r = 0;
        
        while (i < n && j < m) {
            if (p[i] == s[j]) {
                if (p[i] == 'L') {
                    can_l++;
                } else {
                    can_r++;
                }
                i++;
                j++;
            } else {
                if (i == 0) {
                    check = false;
                    break;
                }
                
                if (s[j] == 'L') {
                    if (can_l <= 0) {
                        check = false;
                        break;
                    }
                    can_l--;  
                    j++;
                } 
                else {
                    if (can_r <= 0) {
                        check = false;
                        break;
                    }
                    can_r--;
                    j++;
                }
            }
        }

        while (check && j < m) {
            if (s[j] == 'L') {
                if (can_l <= 0) {
                    check = false;
                    break;
                }
                can_l--;
            } else {
                if (can_r <= 0) {
                    check = false;
                    break;
                }
                can_r--;
            }
            j++;
        }

        if (i < n) check = false;

		if(check) cout <<"YES";else cout << "NO";
		cout << endl;
	}
}