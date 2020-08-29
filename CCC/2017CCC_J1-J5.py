# #######################################
#  @ Canadian Computing Competition     #
#  @ Junior 2017                        #
#  @ Author : Jun Yang                  #
#  @ Time   : 2020-08-28                #
# #######################################

# '''
# Problem J1: Quadrant Selection
# '''
# a=int(input())
# b=int(input())
# if a > 0 and b > 0:
#     print('1')
# elif a < 0 and b > 0:
#     print('2')
# elif a < 0 and b < 0:
#     print('3')
# else:
#     print('4')

# '''
# Problem J2: Shifty Sum
# '''
# a=input()
# b=int(input())
# c=0
# for i in range(b+1):
#     c=c+int(a+i*'0')
# print(c)

# '''
# Problem J3: Exactly Electrical
# '''
# a,b=input().split()
# c,d=input().split()
# e=int(input())
# a=int(a)
# b=int(b)
# c=int(c)
# d=int(d)
# distance=abs(a-c)+abs(b-d)
# if e >= distance and (e-distance)%2==0:
#     print("Y")
# else:
#     print("N")

# '''
# Problem J4: Favourite Times
# '''
# a=int(input())
# b1,b2,b3,b4 = 1,2,0,0
# count=0
# for i in range(a+1):
#     b4=b4+1
#     if b4 >= 10:
#         b3 = b3 + 1
#         b4=0
#     if b3 >= 6:
#         b2 = b2 + 1
#         b3=0
#     if b2 >= 3 and b1 == 1:
#         b1 = 0
#         b2 = 1
#     if b2 >= 10:
#         b1 = b1 + 1
#     if b4 - b3 == b3 - b2 and b1 == 0:
#         count = count + 1
#     elif b4 - b3 == b3 - b2 and b3 - b2 == b2 - b1 and b1 != 0:
#         count = count + 1
# print(count)

# '''
# Problem J5: Nailed It!
# '''
# n = int(input())
# boards = [int(x) for x in input().split()]
# boards.sort()
# maxlength, tmp, hlist, output = 0, boards.copy(), [], 0
# for i in range(n):
#     tmp.pop(0)
#     for j in tmp:
#         if boards[i] == j and boards.count(boards[i]) // 2 > hlist.count(boards[i] + j) or tmp.count(boards[i]) == 0:
#             hlist.append(boards[i] + j)
#             if hlist.count(hlist[-1]) > maxlength:
#                 maxlength, output = hlist.count(hlist[-1]), 1
#             elif hlist.count(hlist[-1]) == maxlength: 
#                 output = output + 1
# print(maxlength, output)