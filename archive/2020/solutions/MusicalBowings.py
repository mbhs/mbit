n = int(input())
s = input().split()
ans = ""
done = 0
if (s[0] == 'B'):
    for i in range(n):
        if (s[i] != 'B'):
            done = i
            cur = s[i]
            break
    if (done == 0):
        for i in range(n):
            if (i % 2 == 0):
                ans += "U "
            else:
                ans += "D "
        print(ans)
        exit()
    else:
        if (s[done] == "D"):
            if (done % 2 == 1):
                for i in range(done):
                    if (i % 2 == 0):
                        ans += "U "
                    else:
                        ans += "D "
            else:
                for i in range(done):
                    if (i % 2 == 0):
                        ans += "D "
                    else:
                        ans += "U "          
        else:
            if (done % 2 == 1):
                for i in range(done):
                    if (i % 2 == 0):
                        ans += "D "
                    else:
                        ans += "U "
            else:
                for i in range(done):
                    if (i % 2 == 0):
                        ans += "U "
                    else:
                        ans += "D "

for i in range(done, n):
    if (s[i] != "B"):
        ans += s[i] + " "
        cur = s[i]
    else:
        if (cur == "D"):
            ans += "U "
            cur = "U"
        else:
            ans += "D "
            cur = "D"

print(ans)
        
            
            

            
        
    
