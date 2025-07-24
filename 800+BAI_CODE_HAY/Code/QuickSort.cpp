#include <bits/stdc++.h>
using namespace std;
void quickSort(int a[], int l, int r){
	int p = a[(l+r)/2];
	int i = l, j = r;
	while (i < j){
		while (a[i] < p)
            i++;

		while (a[j] > p)
			j--;

		if (i <= j)
			swap(a[i++],a[j--]);
	}
	if (i < r)
		quickSort(a, i, r);
	if (l < j)
		quickSort(a, l, j);
}
int main(){
    int a[10]={0,2,3,4,5,6,7,8,9};
    //sort(a,a+10);
    quickSort(a,0,9);
    for (auto it : a)
        cout << it;



    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
#define PHO(i,n) for (int i=1,_n=(n);i<=_n;i++)
#define SZE 100000+5
int n,m,l,a[SZE],d=0;
vector <int> c;

void quickSort(int a[],int l,int r){
    int p=a[(l+r)/2];
    int i=l,j=r;
    while (i<j){
        while (a[i]<p)
            i++;
        while (a[j]>p)
            j--;
        if (i<=j)
            swap(a[i++],a[j--]);
    }
    if (i<r)
        quickSort(a,i,r);
    if (l<j)
        quickSort(a,l,j);
}
int main(){
    scanf("%d",&n);
    scanf("%d",&m);
    scanf("%d",&l);
    PHO(i,n) scanf("%d",a+i);
    quickSort(a,1,n);
    int t=1;
    for (int r=1;r<=n;r++){
        if (r!=1)
            if (a[r]-a[t]>l){
                c.push_back(r-t);
                t=r;
            }
    }
    if (n!=t)
        c.push_back(n-t+1);
    sort(c.begin(),c.end());

    int k=c.size()-1;
    for (int i=k;i>=k-m+1;i--)
        d+=c[i];
    cout << d;
    return 0;
}
*/









