#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        
        if ((n % 2 == 1) && (m % 2 == 1)) {
            if(m % k != 0){
                for (int i = 0; i < n; i++){
                    for (int j = 0; j < m; j++){
                        int cell = ((i * m + j) % k) + 1;
                        cout << cell << " ";
                    }
                    cout << endl;
                }
            }
            else {
                int p = m / k;  // số block trong mỗi hàng
                for (int i = 0; i < n; i++){
                    for (int block = 0; block < p; block++){
                        for (int j = 0; j < k; j++){
                            int cell = ((i + j) % k) + 1;
                            cout << cell << " ";
                        }
                    }
                    cout << endl;
                }
            }
        }
        else {
            if(m % k != 0){
                for (int i = 0; i < n; i++){
                    for (int j = 0; j < m; j++){
                        int cell = ((i * m + j) % k) + 1;
                        cout << cell << " ";
                    }
                    cout << endl;
                }
            }
            else{
                int p = m / k;
                for (int i = 0; i < n; i++){
                    for (int block = 0; block < p; block++){
                        for (int j = 0; j < k; j++){
                            int cell = ((i + j) % k) + 1;
                            cout << cell << " ";
                        }
                    }
                    cout << endl;
                }
            }
        }
    }
}

/*
    n lẻ, m chẵn
    vd: 3 4
    1 2 1 2
    2 1 2 1
    1 2 1 2

    n chẵn, m chẵn
    vd: 4 4
    1 2 1 2
    2 1 2 1
    1 2 1 2
    2 1 2 1

    => m chẵn luôn luôn xếp được, chỉ cần chéo các hàng

    n chẵn m lẻ
    vd: 4 5
    1 2 1 2 1
    2 1 2 1 2
    1 2 1 2 1
    2 1 2 1 2

    => nếu m lẻ, n chẵn => vẫn được

    n lẻ, m lẻ
    vd: 5 3
    1 2 1
    2 1 2
    1 2 1
    2 1 2
    1 2 1

n chẵn
*/
