#include <bits/stdc++.h>

using namespace std;
int N = 1e6;
const int mod = 1e9 + 7;
struct divisor {
    int n;
    int k;
}
vector<divisor> p;
int main(){
    
    int n; cin >> n;
    p.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i].n >> p[i].k;
    }
    int numDivisors = 1;
    for (int i = 1; i <= n; i++) {
        numDivisors *= p[i].k + 1;
    }
    
    return 0;
}