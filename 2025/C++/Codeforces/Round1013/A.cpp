/*
Status: Accepted
*/
#include <bits/stdc++.h>

using namespace std;
int cnt[6] = {3,1,2,1,0,1};

bool check(vector<int> &c) {
    for (int i = 0; i < 6; i++) {
        if (c[i] < cnt[i]) {
            return false;
        }
    }
    return true;
}
int main(){
    int t; cin >> t;
    while(t--) {
        int count = 0;
        vector<int> c(6, 0);
        int n; cin >> n;
        vector<int>a(n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];            
        }
        
        for (int i = 0; i < n; i++) {
            if (a[i] <= 5) {
                c[a[i]]++;
                if (check(c)) {
                    ans = i + 1;
                    break;
                }
            }               
        }
        cout << ans << endl;
    }
    return 0;
}