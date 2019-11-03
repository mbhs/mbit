months = ['January','February','March','April','May','June','July','August','September',
          'October','November','December']
def dayrank(s):
    return 100*months.index(s.split(' ')[0]) + int(s.split(' ')[1])

cal = {}
n = int(input())
for count in range(n):
    line = input().strip().split(" ")
    if line[0] == 'ADD':
        if line[1] not in cal.keys():
            cal[line[1]]=line[2]+" "+line[3]
    elif line[0] == 'DELETE':
        cal.pop(line[1],0)
    elif line[0] == 'RESCHEDULE':
        if line[1] in cal.keys():
            cal[line[1]]=line[2]+" "+line[3]
    elif line[0] == 'PRINT':
        if line[1] in cal.keys():
            print(cal[line[1]])
        else:
            print("NOT SCHEDULED")
    
print(" ".join([x[0] for x in sorted(sorted(cal.items(),key=lambda y: y[0]), key=lambda y: dayrank(y[1]))]))