#include <bits/stdc++.h>
#define int long long
using namespace std; 

signed main(){
    int t; cin >> t;
    while(t--) {
        int x,y;
        cin >> x >> y;
        if(x>=y) {
            cout << "Y" << endl;
            continue;
        }
        if (x  % 2== 1) x--;

        if (x * 3 / 2 >= y) {
            cout << "Y" << endl;
            continue;
        }

        if (x <= 2) {
            cout << "N";
        }
        else cout <<"Y";
        cout <<endl;
    }
}
