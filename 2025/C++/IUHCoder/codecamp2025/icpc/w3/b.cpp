#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int oo = 1e9 + 7;
struct customer {
    int idx;
    int a;
    int s;
    int p;
};
bool compare(customer&a, customer&b) {
    return a.a < b.a;
}
signed main() {
    int n; cin >> n;
    vector<customer> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].idx >> a[i].a >> a[i].s >> a[i].p;
    }
    sort(a.begin() + 1, a.end(), compare);
    vector<bool> happy(n + 1, true);
    int prev = a[1].a + a[1].s;

    for (int i = 2; i <= n; i++) {  
        int time_cur = max(prev, a[i].a);
        int max_k = a[i].p + a[i].a;
        if (max_k >= time_cur) {
            prev = time_cur + a[i].s;
        }
        else {
            happy[i] = false;
        }
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (happy[i]) ans.push_back(a[i].idx);
    }
    sort(ans.begin(), ans.end());
    for (auto i : ans) cout << i << " ";
}