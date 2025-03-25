/*
Status: Accepted
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){

    int t; cin >> t;
    while(t--){
        int n, x; cin >> n >> x;
        vector<int> skill(n);
        for (int i = 0; i < n; i++) {
            cin >> skill[i];
        }
        sort(skill.begin(), skill.end());
        int idx = n -1;
        int teamMember = 0;
        int minPower = LLONG_MAX;
        bool valid = false;

        int ans = 0;

        while (idx >= 0) {
            if (valid == false) {
                teamMember++;
                minPower = min(minPower, skill[idx]);
                int tempValue = teamMember * minPower;
                if (tempValue >= x) {
                    valid = true;
                }
            }
            if (valid) {
                ans++;
                teamMember = 0;
                minPower = LLONG_MAX;
                valid = false;
            }    
            idx--;
        }
        cout << ans << endl;
    }
    return 0;
}