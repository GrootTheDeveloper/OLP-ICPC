#include <bits/stdc++.h>
using namespace std;
#define MAX 10000+5
int n,a[MAX],d=0;
double tbc;
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",a+i);
        if (a[i]<0){
            d+=1;
            tbc+=a[i];
        }

    }
    if (tbc!=0)
        cout << fixed << setprecision(2) << tbc/d; 
    else
        cout << -1;
}
