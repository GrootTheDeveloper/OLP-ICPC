#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    freopen("BANGRON.INP", "r", stdin);
    freopen("BANGRON.OUT", "w", stdout);
    string s; cin >> s;
    int n = s.size();
    int freq[3] = {0, 0, 0}; // O = 0, L = 1, P = 2
    int j = 0;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        while (j < n && max({freq[0], freq[1], freq[2]}) < 3) {
            if (s[j] == 'O') freq[0]++;
            else if (s[j] == 'L') freq[1]++;
            else freq[2]++;
            j++;
        }
        if (max({freq[0], freq[1], freq[2]}) >= 3) {
            ans += n - j + 1; 
        }
        if (s[i] == 'O') freq[0]--;
        else if (s[i] == 'L') freq[1]--;
        else freq[2]--;
    }

    cout << ans;
}
