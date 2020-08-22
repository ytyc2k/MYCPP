'''
Problem J1: Dog Treats
'''
# S = int(input())
# M = int(input())
# L = int(input())
# H = 1 * S + 2 * M + 3 * L
# print('happy') if H > =10 else print('sad')

'''
Problem J2: Epidemiology
'''
P = int(input())
N = int(input())
R = int(input())
S, i = 0, 0
while S < P:
    S = S+N*R**i
    i = i+1
print(i)

'''
Problem J3: Art
'''
# N = int(input())
# lst=[ tuple(map(int,(input().split(',')))) for i in range(N) ]
N=5
lst=[(44,62),(34,69),(24,78),(42,44),(64,10)]
lst.sort()
print(lst[0][0]-1,lst[-1][1]-1,sep=',')
print(lst[-1][0]+1,lst[0][1]+1,sep=',')

'''
Problem J4: Cyclic Shifts
'''
T='ABCCDEABAA'
S='ABCDE'
T='ABCDDEBCAB'
S='ABA'
lst=[S[-i-1:]+S[:-i-1] for i in range(len(S))]
for x in lst:
    if x in T:
        print('yes')
        break;
else:
    print('no')
