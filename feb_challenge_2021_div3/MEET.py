import datetime
t = int(input())
while(t):
    p = datetime.datetime.strptime(input(), "%I:%M %p")
    n = int(input())
    for _ in range(n):
        a,b,c,d = input().split()
        if datetime.datetime.strptime(a+' '+b, "%I:%M %p") <= p and datetime.datetime.strptime(c+' '+d, "%I:%M %p") >= p:
            print(1, end="")
        else:
            print(0, end="")
    print("")
    t -= 1
