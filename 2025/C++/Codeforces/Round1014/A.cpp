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
        vector<int>a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int res = *max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end());
        cout << res << endl;
    }
    return 0;
}