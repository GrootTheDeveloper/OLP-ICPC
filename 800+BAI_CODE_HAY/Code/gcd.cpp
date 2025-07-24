#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    if (b==0) return a;
    return gcd(b,a%b);

}

int main(){
    int t,x,y;
    cin >> t;
    while (t-->0){
        cin >> x >> y;
        int k=gcd(x,y),d=0;
        for (int i=0;i<y;i+=k){
            d+=(k==gcd(i+x,y));
        }
        cout << d << endl;
    }
    return 0;
}
