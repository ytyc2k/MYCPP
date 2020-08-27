'''
Problem J1: Winning Score
'''
# A3=int(input())
# A2=int(input())
# A1=int(input())
# B3=int(input())
# B2=int(input())
# B1=int(input())
# A=A3*3+A2*2+A1
# B=B3*3+B2*2+B1
# if A > B:
#     print('A')
# elif B > A:
#     print('B')
# else:
#     print('T')

'''
Problem J2: Time to Decompress
'''
# lst1=[]
# lst2=[]
# L=int(input())
# for i in range(L):
#     a,b=input().split()
#     lst1.append(int(a))
#     lst2.append(b)
# for i in range(L):
#     print(lst2[i]*lst1[i])

'''
Problem J3: Cold Compress
'''
# lst1, lst2=[],[]
# index=0
# for i in range(int(input())):
#     a=list(input())
#     while a:
#         for j in range(a.count(a[0])):
#             if a[0] == a[j]:
#                 index=index+1
#             elif a[0] != a[j]:
#                 break
#         lst1.append(str(index))
#         lst1.append(str(a[0]))
#         del a[0:index]
#         index=0
#     lst2.append(' '.join(lst1))
#     lst1.clear()
# for j in range(len(lst2)):
#     print(lst2[j])

# '''
# Problem J4/S1: Flipper
# '''
# M1=[1,2]
# M2=[3,4]
# for i in input():
#     if i=='V':
#         M1.reverse()
#         M2.reverse()
#     elif i=='H':
#         M1,M2=M2,M1
# print(M1[0],M1[1])
# print(M2[0],M2[1])

'''
Problem J5: Rule of Three
'''
import time
t1=time.time()
lst=[]
rlst=[]
# for i in range(3):
#     lst.append((input().split()))
# S, I, F = input().split()
# S = int(S)
lst=[('AA','AB'),('AB','BB'),('B','AA')]
S, I, F = 12,'AB','AAAB'
def rec(S, I, rlst):
    if S == 0 and I == F:
        return rlst
    elif S == 0:
        return False
    for rule, (a, b) in enumerate(lst, start = 1):
        index = -1
        while True:
            index = I.find(a, index + 1)
            if index == -1:
                break
            sub_str = I[:index] + b + I[index + len(a):]
            ans = rec(S - 1, sub_str[:], rlst + [(rule, index, sub_str)])
            if ans:
                return ans
    return False
if(rec(S,I,rlst) == False):
    print("Impossible")
else:
    ans = rec(S,I,rlst)
    for i, j, k in ans:
        print(i, j + 1, k)
t2=time.time()
print(t2-t1)

# '''
# Problem J5: Rule of Three
# '''
# import time
# t1=time.time()
# Rule=(('AA','AB'),('AB','BB'),('B','AA'))
# N=6
# INPT,OTPT='AB','AAAB'
# def f(a,b,c,ss):
#     for x in Rule:
#         i=0
#         while (n:=ss.find(x[0],i))!=-1:
#             s=ss[:n]+x[1]+ss[n+len(x[0]):]
#             lst.append((a+'-'+str(Rule.index(x)+1),b+'-'+str(n+1),c+'-'+s,s))
#             i=n+1
#     return lst
# lst=[('','','',f'{INPT}')]
# for i in range(N):
#     for x in lst[-len(lst):]:
#         f(x[0],x[1],x[2],x[-1])
# print(len(lst))
# print(lst[-100])
# # for x in lst:
# #     if x[-1]==OTPT:
# #         print(x)
# t2=time.time()
# print(t2-t1)

    