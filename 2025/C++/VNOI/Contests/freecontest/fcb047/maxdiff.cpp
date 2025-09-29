#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n; cin >> n;
    vector<int> a(3 * n + 1);
    for (int i = 1; i <= 3 * n; i++) {
        cin >> a[i];
    }

    /*
    Xét đến i, max_F = max_pref[i] - min_suff[i]

    max_pref[i] là tổng lớn nhất gồm n phần tử khi xét i phần tử đầu tiên

    min_suff[i] là tổng bé nhất gồm n phần tử khi xét 3 * n - i phần tử cuối cùng
    */
    vector<int> pref(3 * n + 1, 0), suff(3 * n + 2, 0);
    
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + a[i];
    }

    for (int i = 3 * n; i > 2 * n; i--) {
        suff[i] = suff[i + 1] + a[i];
    }

    priority_queue<int> maxQ;
    priority_queue<int, vector<int>, greater<int>> minQ;

    for (int i = 1; i <= n; i++) {
        minQ.push(a[i]);
    }
    for (int i = 2 * n + 1; i <= 3 * n; i++) {
        maxQ.push(a[i]);
    }

    int f = 0;

    for (int i = n + 1; i <= 2 * n; i++) {
        if (a[i] > minQ.top()) {
            pref[i] = pref[i - 1] - minQ.top() + a[i];    
            minQ.pop();
            minQ.push(a[i]);
        }
        else {
            pref[i] = pref[i - 1];
        }
    }

    for (int i = 2 * n; i >= n + 1; i--) {
        if (a[i] < maxQ.top()) {
            suff[i] = suff[i + 1] - maxQ.top() + a[i];
            maxQ.pop();
            maxQ.push(a[i]);
        }
        else {
            suff[i] = suff[i + 1];
        }
    }

    for (int i = n; i <= 2 * n; i++) {
        f = max(f, pref[i] - suff[i + 1]);
//        cout << pref[i] << " " << suff[i + 1] << endl;
    }

    cout << f;

}