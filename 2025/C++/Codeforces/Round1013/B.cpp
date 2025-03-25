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
        if (n % 2 == 0) {
            cout << -1;
        }
        else {
            int even = 2;
            int odd = 1;
            while (odd <= n) {
                cout << odd << " ";
                odd += 2;
            }
            while (even <= n){
                cout << even << " ";
                even += 2;
            }
        }
        cout << endl;
    }
    return 0;
}