#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int b, bo, yo,sy,sm,y;
    cin >> b >> bo >> yo >> y >> sy >> sm;
    int total_month = (y - yo)*12;
    int chu_ky_de_cho = sy * 12 + sm;
    
    int chu_ky = total_month / chu_ky_de_cho;

    cout << total_month << " " << chu_ky_de_cho << " " << chu_ky <<endl;
    int bits = pow(b,bo);
    while(chu_ky--) {
        bits *= b;
    }
    // b^(bits)
    // tìm n < b^(bits)
    
    cout << bits <<" ";
    int gt = 1;
    int i;
    for(i = 2;gt < bits ; i++){
        gt *= i;
    }
    cout << i;
}