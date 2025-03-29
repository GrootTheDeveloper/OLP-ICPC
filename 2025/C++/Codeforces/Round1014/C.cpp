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
        vector<int> a(n);
        int S = 0;
        int max_value = -1;
        pair<bool, int> odd = {false, 0};
        pair<bool, int> even = {false, 0};
        for (int i =0 ; i < n; i++) {
            cin >> a[i];
            S+= a[i];
            max_value = max(max_value, a[i]);
            if (a[i] % 2 == 0) {
                even.first = true;
            }
            else {
                odd.second ++;
                odd.first = true;
            }
        }
        if (odd.first && even.first) {
            int res = max(max_value,S - odd.second + 1);
            cout << res;
        }
        else {
            cout << max_value;
        }
        cout << endl;
    }
    return 0;
}