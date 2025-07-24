def ucln(a,b):
    if b==0:
        return a
    else:
        return ucln(b,a%b)
x,y=map(int,input().split())
print(ucln(x,y),int((x*y//(ucln(x,y)))))
