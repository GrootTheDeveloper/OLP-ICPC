#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {
    int n;
    int a, b; 
    cin >> n >> a >> b;
    int fb = 0, f_f = 0, f_b = 0;
    for (int i = 1; i <= n; i++) {
        int val = i;
        if (val % a == 0 && val % b == 0) {
            fb++;   
        }
        else if (val % a == 0) {
            f_f++;
        }
        else if (val % b == 0) {
            f_b++;
        }
    }
    cout << f_f << " " << f_b<< " " << fb  ;
}