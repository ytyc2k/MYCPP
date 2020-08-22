# '''
# CCC Senior S1:Surmising a Sprinter’s Speed
# '''
# N=int(input('Please input an integer N (2<N<=1000):'))
# data=[]
# for i in range(N):
#     data.append(list(map(int,input('Please input 2 integer, seperate with a space.').split())))
# # data=[[20,-5],[0,-17],[10,31],[5,-3],[30,11],]
# data.sort()
# print(max(map(lambda x,y:abs(x[1]-y[1])/(x[0]-y[0]),data[1:],data[:-1])))


# '''
# CCC Senior S2:Escape Room
# '''
# def GetSubBranch(x):
#     for i in range(1,x+1):
#         for j in range(1,x+1):
#             if i*j==x and i>0 and i<=M and j>0 and j<=N:
#                 print(i,j)
#                 ss.append(rooms[(i-1)*N+j-1])
#     return ss
# M,N=3,4
# rooms = [3, 10, 8, 14, 
#          1, 11, 12, 12, 
#          6, 2, 3, 9]
# ss=[rooms[0]]
# while ss:
#     if rooms[-1] in ss:
#         print('yes')
#         break
#     for i in ss:
#         print(ss,i)
#         ss.remove(i)
#         rooms[rooms.index(i)]=0
#         GetSubBranch(i)


# '''
# CCC S3: Searching for Strings
# '''
# ss,s1='abacabaa','aab'
# print(len([ss.find(x) for x in [s1[-i-1:]+s1[:-i-1] for i in range(len(s1))] if ss.find(x)!=-1]))


# '''
# 2020 CCC S4: Swapping Seats
# '''
# ss='BABCBCACCA'
# lena,lenb,lenc=ss.count('A'),ss.count('B'),ss.count('C')
# lst=list(set(['A'*lena+'B'*lenb+'C'*lenc,'A'*lena+'C'*lenc+'B'*lenb]))
# lstr=[x[-i-1:]+x[:-i-1] for x in lst for i in range(len(x))]
# n=min([sum([1 for j in range(len(ss)) if x[j] != ss[j]]) for x in lstr])
# print([i for i in range(n) if n in range(i+1,(2*i)+1)][0])


'''
CCC S5: Josh’s Double Bacon Deluxe
'''
lst1=[1,2,3,1,1,2,3]
lst2=lst1.copy()
n=len(lst1)
c1=lst1.count(1)
c2=lst1.count(2)
p=c1/n
pp=1
lst1.pop(lst1.index(2))
lst2.pop(0)
for i in lst2:
    if lst1.count(i) > 0:
        lst1.pop(lst1.index(i))
        lst2.pop(0)
    elif lst1.count(i) == 0:
        pp = pp*((len(lst1)-lst1.count(3))/len(lst1))
c=c2/n*pp
p=p+c
print(p)