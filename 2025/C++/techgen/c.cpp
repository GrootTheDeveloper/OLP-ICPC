#include <bits/stdc++.h>
#define int long long  
using namespace std;

int gt(int n) {
    if (n == 0) return 1;
    if (n == 1) return 1;
    return gt(n - 1) * n;
}

int A(int k, int n) {
    return gt(n) / gt(n - k);
}
signed main() {
    
    int a = 10, b = 25;
    while (b > 0) {
        int temp = a;
        a = b;
        b = temp % a;
    }
    cout << a;
}