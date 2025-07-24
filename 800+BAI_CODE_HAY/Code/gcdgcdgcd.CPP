#include <bits/stdc++.h>
using namespace std;
int phi(int n) {
    int result = n;
    for(int p = 2; p * p <= n; ++p)
        if (n % p == 0) {
            while (n % p == 0) n /= p;
            result -= result / p;
        }
    if (n > 1) result -= result / n;
    return result;
}
void solve(int x, int y) {
    int n = y / __gcd(x,y);
    cout << phi(n) << endl;
}
int main() {
    int x,y,t;
    cin >> t;
    while (t--) {
        cin >> x >> y;
        solve(x,y);
    }
    return 0;
}
