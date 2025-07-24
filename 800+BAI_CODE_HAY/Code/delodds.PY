import sys
sys.stdin=open("delodds.inp",'r')
sys.stdout=open('delodds.out','w')
n=int(input())
a=list(map(int,input().split()))
c,l=0,0
for i in a:
    if (i%2==0):
        c+=1 
    else:
        l+=1
print(min(c,l))
