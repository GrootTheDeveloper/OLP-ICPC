#include <bits/stdc++.h>

using namespace std;

int dq(int n, int k) {
    if (n == 1) return 1;
    int half = n + 1 >> 1;
    if (half >= k) {
        if (2 * k > n) return (2 * k) % n;
        return 2 * k;
    }
    int temp = dq(n / 2, k - half);
    if (n & 1) return 2 * temp + 1;
    return 2 * temp - 1;
} 
int main(){
    int q; cin >> q;
    while(q--){
        int n, k; cin >> n >> k;
        int now = 0;
            cout << dq(n, k) << endl;

    }
    return 0;
}x