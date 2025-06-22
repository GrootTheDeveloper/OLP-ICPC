#include <bits/stdc++.h>
#define int long long
using namespace std; 

int maxPrime = sqrt(1000000000);

int calcNum(int n) {
    int total = 0;
    while (n) {
        total += n %10;
        n/=10;
    }
    return total;
}
bool check(int n) {
    int temp = n;
    for (int i = 2; i * i <= n; i++) {
        if (temp % i == 0) {
            return false;
        }
    }
    return true;
}
int calcPrime(int n) {
    int total = 0;
    int temp = n;
    for (int i = 2; i * i <= n; i++) {
        while(temp % i == 0) {
            total += calcNum(i);
            temp /= i;
        }
    }
    if (temp > 1) total += calcNum(temp);
    return total;
}

signed main(){
    int t; cin >> t;
    
    while(t--) {
        int n; cin >> n;
        int left = calcNum(n);
        int right = calcPrime(n);
        cout << (check(n) ? 0 : ((left == right) ? 1 : 0)) << endl;
    }
}
