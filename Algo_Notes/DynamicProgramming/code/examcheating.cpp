#include <bits/stdc++.h>
using namespace std;

const int oo = 1e9 + 7;

vector<int> a;
vector<int> b;
int n,p,k; 
int r; 
int s; 

int main() {
    cin >> n >> p >> k;
    cin >> r;
    a.resize(r + 1); 
    for (int i = 1; i <= r; i++) cin >> a[i];
    cin >> s;
    b.resize(s + 1);
    for (int i = 1; i <= s; i++) cin >> b[i];
    int f[n + 1][p + 1][3];
    memset(f, 0, sizeof(f));
    
    for (int i = 1; i <= n; i++) {
        for (int pi = p; pi >= 0; pi--) {
            // nếu ko gian lận
            for (int ki = min(1, i - k); ki < i; ki++) {
                f[i][pi][0] = f[k][]
            }
        }
    }
}
