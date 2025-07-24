t=int(input())
for k in range(t):
    s1=input()
    s2=input()
    m=len(s1)
    n=len(s2)
    t=m+n
    m-=1
    n-=1
    while (m>=0 and n>=0):
        if (s1[m]==s2[n]):
            t-=2
            m-=1
            n-=1
        else:
            break
    print(t)
