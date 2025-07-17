#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

signed main() {
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<int> div;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int maxVal = *max_element(a.begin() + 1, a.end());

    for (int i = 2; ; i++) {
        if (i * i > maxVal) break;
        div.push_back(i * i);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int t = gcd(a[i], a[j]);
            bool check = false;
            for (auto c : div) {
                if (t % c == 0) {
                    check = true;
                    break;
                }
            }
            if (check == false) {
                ans++;
            }
        }
    }
    cout << ans;
}