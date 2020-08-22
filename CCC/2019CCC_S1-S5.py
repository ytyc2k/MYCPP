'''
Problem J4/S1: Flipper
'''
M1=[1,2]
M2=[3,4]
for i in input():
    if i=='V':
        M1.reverse()
        M2.reverse()
    elif i=='H':
        M1,M2=M2,M1
print(M1[0],M1[1])
print(M2[0],M2[1])

