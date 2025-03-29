/*
Status: Accepted
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s[2];
        cin >> s[0] >> s[1];
        int one_at_oddIdx = 0, one_at_evenIdx = 0;
        int zero_at_oddIdx = 0, zero_at_evenIdx = 0;
        for (int i = 0; i < n; i++){
            if (s[0][i] == '1') {
                if (i % 2 == 0) {
                    one_at_evenIdx++;
                }
                else {
                    one_at_oddIdx++;
                }
            }
            if (s[1][i] == '0') {
                if (i % 2 == 0) {
                    zero_at_evenIdx++;
                }
                else {
                    zero_at_oddIdx++;
                }
            }
        }
        bool check = false;

        if ((one_at_oddIdx <= zero_at_evenIdx) && (one_at_evenIdx <= zero_at_oddIdx)) {
            check = true;
        }
        if (check) cout << "YES";
        else cout << "NO";
        cout << endl;

    }
    return 0;
}