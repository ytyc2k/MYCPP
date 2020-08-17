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
#             if i*j==x and i>0 and i<=N[0] and j>0 and j<=N[1]:
#                 print(i,j)
#                 ss.append(rooms[(i-1)*4+j-1])
#     return ss
      
# N=[3,4]
# rooms = [3, 12, 7, 14, 7, 11, 5, 6, 6, 2, 12, 9]
# # rooms = [3, 10, 8, 14, 1, 11, 12, 12, 6, 2, 3, 9]

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
# ss='abacabaa'
# s1='aab'
# ts=[]
# i=0
# for x in s1:
#     ts.append(s1)
#     s1=s1[1:]+s1[0]
# for x in ts:
#     if ss.find(x):
#         i+=1
# print(i)

'''
CCC S4: Swapping Seats
'''
ss='BABCBCACCA'
lena,lenb,lenc=ss.count('A'),ss.count('B'),ss.count('C')
lst=list(set(['A'*lena+'B'*lenb+'C'*lenc,'A'*lena+'C'*lenc+'B'*lenb]))
lstr=[x[-i-1:]+x[:-i-1] for x in lst for i in range(len(x))]
n=min([sum([1 for j in range(len(ss)) if x[j] != ss[j]]) for x in lstr])
print([i for i in range(n) if n in range(i+1,(2*i)+1)][0])