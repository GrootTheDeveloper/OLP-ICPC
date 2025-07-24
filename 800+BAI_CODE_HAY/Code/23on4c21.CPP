#include <bits/stdc++.h>
using namespace std;
#define MAX 100+5
int l,s,a[MAX];

int main(){
    scanf("%d",&l);
    scanf("%d",&s);
    if (9*l<s || s==0 && l>1){
        cout << -1;
        return 0;
    }
    int  t=s-1;
    for (int i=l-1;i>0;i--){
        if (t>=9) {a[i]=9;t-=9;}
        else if(t!=0) {a[i]=t;t=0;}
        else break;
    }
    a[0]=t+1;
    for (int i=0;i<l;i++){cout << a[i];a[i]=0;}
    cout << endl;
    t=s;
    for (int i=0;i<l;i++){
        if (t>=9){
            a[i]=9;
            t-=9;
        }
        else if (t!=0) {a[i]=t;t=0;}
        else break;
    }
    for (int i=0;i<l;i++) 
    {cout << a[i];a[i]=0;}

    return 0;

}
