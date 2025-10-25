#include <bits/stdc++.h>
#define int long long
using namespace std;

int askP(int l, int r) {
    cout << 1 << " " << l << " " << r << endl;
    int x; cin >> x;
    return x;
}
int askA(int l, int r) {
    cout << 2 << " " << l << " " << r << endl;
    int x; cin >> x;
    return x;
}

signed main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n; // len of perm
        /*
        p = n * (n + 1) / 2;
        a = n * (n + 1) / 2 + (r - l + 1)

        giả sử 
        p = [2, 1    , 3    , 5    , 4]
        a = [2, 1 + 1, 3 + 1, 5 + 1, 4]
        sum p = 15
        sum a = 15 + (4 - 2 + 1) = 18
        range = p - a

        => tìm l sao cho p[1..l] = a[1..l]
        kết quả là (l, l + range - 1)
        */
        int sumP = n * (n + 1) / 2;
        int sumA = askA(1, n);
        int range = sumA - sumP;
        int ansL = 0;
        int l = 1, r = n;
        while (l <= r) {
            int mid = l + r >> 1;
            int resP = askP(1, mid);
            int resA = askA(1, mid);
            if (resP == resA) {
                ansL = mid;
                l = mid + 1;
            }
            else if (resP < resA) {
                r = mid - 1;
            }
        }
        cout << "! " << ansL + 1 << " " << ansL + range << endl;
    }
}
