#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

const int oo = 1e18;
const int MAXN = 100005;
int digit_sum(int n) {
    if (n <= 0) return 0;
    int res = 0;
    int p = 1;
    while (p <= n) {
        int div = n / (p * 10);
        int mod = n % (p * 10);

        res += div * 45 * p;

        int high = mod / p;    
        int low  = mod % p; 

        res += (high * (high - 1) / 2) * p;

        res += high * (low + 1);

        p *= 10;
    }
    return res;
}
signed main() {
    /*
    1 chu so = 9 so
    2 chu so = 90 so = 90*2 chu so
    3 chu so = [100 .. 999] = 900 * 3 chu so
    n chu so = 9 * 10^{n - 1} * n
    --------------
    Tong cac chu so trong block n:
    block[1] : cac chu so xuat hien 1 lan = 45
    block[2] : 90 so 
                hang chuc : moi so xuat hien 10 lan --> 10 * (1 + 2 + 3 + ... + 9) = 10*45; 
                hang don vi : moi so xuat hien 9 lan --> 9 * 45;
    block[3] : 900 so
                hang tram : moi so xuat hien dung 100 lan --> 100 * 45
                hang chuc : moi so xuat hien dung 90 lan --> 90 * 45
                hang don vi: moi so xuat hien dung 90 lan --> 90 * 45
                = 45 * 100 + 45 * 90 + 45 * 90 = 45 * 100 + 45 * (90 + 90)

    block[n] : 9 * 10^{n - 1} so --> sum = 45 * 10^{n - 1} + (n - 1) * 45 * 9 * 10^{n - 2} = 45 * [10^{n - 1} + (n - 1) * 9 * 10^{n - 2}]
                                                                                       = 45 * 10^{n - 2} * [10 + (n - 1) * 9] 
    */
   
    int t; cin >> t;
    vector<int> p10(19, 1);
    for (int i = 1; i <= 18; i++) p10[i] = p10[i- 1] * 10;

    vector<int> blocks(19, 0), g(19, 0);
    for (int i = 1; i <= 18; i++) {
        blocks[i] = 9 * p10[i - 1];
        g[i] = blocks[i] * i;
    }

    vector<int> sum_in_blocks(19, 0), f(19, 0);

    sum_in_blocks[1] = 45;
    for (int i = 2; i <= 18; i++) {
        sum_in_blocks[i] = 45 * p10[i - 2] *(10 + (i - 1) * 9); 
    } 
    for (int i = 1; i <= 18; i++) {
        f[i] = f[i-1] + sum_in_blocks[i];
    }
    vector<int> fd(19, 0);
    for (int i = 1; i <= 18; i++) {
        fd[i] = fd[i-1] + g[i];
    }
    while (t--) {
        int k; cin >> k;
        int l = 0, r = 18, d = 0;
        while (l <= r) {
            int mid = l + r >> 1;
            if (fd[mid] < k) { 
                d = mid; 
                l = mid + 1; 
            }
            else r = mid - 1;
        }
        int ans = f[d];

        int len = d + 1;
        int remain = k - fd[d];
        int start = p10[len - 1];

        int full = remain / len;  
        int rem  = remain % len; 

        if (full > 0) {
            int last_full = start + full - 1;
            ans += digit_sum(last_full) - digit_sum(start - 1);
        }
        if (rem > 0) {
            int num = start + full;    
            string s = to_string(num);
            for (int i = 0; i < rem; i++) ans += (s[i] - '0');
        }

        cout << ans << endl;
    }
    return 0;
}