#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;

int main(){
    freopen("dpfibo1.inp", "r", stdin);
    freopen("dpfibo1.out", "w", stdout);
    
    int n; cin >> n;
    int f = 1, s = 1;
    if (n == 1 || n == 2) {
        cout << 1;
        return 0;
    }

    int idx = 2;
    int cur = 0;
    while(true) {
        idx++;
        (cur = f + s) %= mod;
        
        if (idx == n) {
            cout <<  cur;
            return 0;
        }
        f = s % mod;
        s = cur % mod;
    }
    cout << cur ;
    return 0;
}