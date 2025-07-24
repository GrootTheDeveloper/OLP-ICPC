#include <bits/stdc++.h>
using namespace std;

int a[100], cnt[1000006], divs[1000006], num;
long long ans;
void sie(){
    for (int i = 2; i <= 1e6; i++)
    if (!divs[i]){
        for (int j = i; j <= 1e6; j += i)
            divs[j] = i;
    }
}

void add(int x){
    int lim = 0;
    while (x != 1){
        a[++lim] = divs[x];
        while (x % a[lim] == 0)
            x /= a[lim];
    }
    int MASK = (1 << lim) - 1, excl = 0;
    for (int mask = 1; mask <= MASK; mask++){
        int mul_pr = 1;
        for (int i = 0; i < lim; i++)
            if (mask >> i & 1)
                mul_pr *= a[i + 1];
        if (__builtin_popcount(mask) & 1)
            excl += cnt[mul_pr];
        else
            excl -= cnt[mul_pr];
        cnt[mul_pr]++; 
    }
    ans += num - excl;
    ++num;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    sie();
    while (n--){
        int x; cin >> x;
        add(x);
    }
    cout << ans;
}