def gcd(a,b):
    if (b==0):
        return a 
    return gcd(b,a%b)
def lcm(a,b):
    return a//gcd(a,b)*b


x,n,m=map(int,input().split())
print(n//(lcm(x,m)//x))
