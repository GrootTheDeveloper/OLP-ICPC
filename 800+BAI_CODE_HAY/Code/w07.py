def ucln(a,b):
    if b==0:
        return a
    else:
        return ucln(b, a%b)
m,n= map(int,input().split())
print(ucln(m,n))
