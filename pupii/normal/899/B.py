l=[
31,28,31,30,31,30,31,31,30,31,30,31,
31,28,31,30,31,30,31,31,30,31,30,31,
31,28,31,30,31,30,31,31,30,31,30,31,
31,29,31,30,31,30,31,31,30,31,30,31,
]
l+=l
n=int(input())
k=list(map(int,input().split()))
lim=12*4*2-n+1
for i in range(0,lim):
    if k==l[i:i+n]:
        print("YES");exit()
print("NO")