#include<iostream>
using namespace std;
struct dt{
    int l,r;
};
dt sol[100000];
int dem=0;
void Tower(int n , int a, int b, int c ){
	if(n==1){
		dem++;
		sol[dem].l=a;
		sol[dem].r=c;
		return;
	}
	Tower(n-1,a,c,b);
	Tower(1,a,b,c);
	Tower(n-1,b,a,c);
	}
int main(){
	int a=1, b=2, c=3;
	int n;
	cin>>n;
	Tower(n,a,b,c);
	cout << dem << endl;
	for (int i=1;i<=dem;i++)
        cout << sol[i].l << ' ' << sol[i].r << endl;
    return 0;
}
