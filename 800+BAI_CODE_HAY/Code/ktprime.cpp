#include <bits/stdc++.h>
using namespace std;
#define MAX 10000+5
int n;

bool nt(int n){
    if (n<=3)
        return n>1;
    else if (n%2==0 || n%3==0)
        return 0;
    int i=5;
    while (i*i<=n){
        if (n%i==0 || n%(i+2)==0)
            return 0;
        i+=6;
    }
    return 1;
}

int main(){
    scanf("%d",&n);
    if (nt(n))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
