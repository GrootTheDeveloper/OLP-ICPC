#include <bits/stdc++.h>
#define int long long
using namespace std;


struct prob {
    int val;
    int idx;
};
int n; vector<prob> a;

bool checkSubtask1() {
    return n <= 1024;
}

bool compare(const prob &cur, const prob &other) {
    return cur.val > other.val;
}

bool compare2(const prob &cur, const prob &other) {
    return cur.val < other.val;
}

void doSubtask1() {
    vector<char>ans(n + 1);
    sort(a.begin() + 1, a.end(), compare);
    for (int i = 1; i <= n; i++) { // con thứ i
        int j = i + 1;
        int value = a[i].val;
        while (j <= n && a[j].val == a[i].val) {
            j++;
        }
        for (int k = j; k <= n; k++) {
            value += a[k].val;
        }
        bool check = true;
        if (j == n + 1) check = false;
        if (a[j].val == a[i].val && value == a[j].val) check = false;
        if (check == true) {
            for (int k = i - 1; k >= 1; k--) {
                if (a[k].val < value) {
                    value += a[k].val;
                }
                else {
                    check = false;
                    break;
                }
            }
        }
        if (check == false) {
            ans[a[i].idx] = 'N';
        }
        else ans[a[i].idx] = 'T';
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i];
    }
}

void doSubtask2() {
    vector<char> ans(n + 1);
    sort(a.begin() + 1, a.end(), compare2);
    vector<int> f(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1] + a[i].val;
    }
    vector<int> pref(n + 1, 0), suff(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        pref[i] = max(pref[i - 1], a[i].val - f[i - 1] + 1);
    }

    for (int i = n; i >= 1; i--) {
        suff[i] = max(suff[i + 1] - a[i].val, a[i].val + 1);
    }

    for (int i = 1; i <= n; i++) {
        if (a[i].val >= pref[i - 1] && (a[i].val + f[i - 1]) >= suff[i + 1]) {
            ans[a[i].idx] = 'T';
        }
        else {
            ans[a[i].idx] = 'N';
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i];
}

signed main() {
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].val; a[i].idx = i;
    }
    if (checkSubtask1()) return doSubtask1(), 0;
    
//    doSubtask2();
}