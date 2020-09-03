# #######################################
#  @ Canadian Computing Competition     #
#  @ Junior 2016                        #
#  @ Author : Jun Yang                  #
#  @ Time   : 2020-09-01                #
# #######################################

# '''
# Problem J1: Tournament Selection
# '''
# lst = [input() for i in range(6)]
# if lst.count('W') >=5:
#     print(1)
# elif lst.count('W') == 3 or 4:
#     print(2)
# elif lst.cout("W") == 0:
#     print(-1)
# else:
#     print(3)

# '''
# Problem J2: Magic Squares
# '''
# lst1=[int(i) for i in input().split()]
# lst2=[int(i) for i in input().split()]
# lst3=[int(i) for i in input().split()]
# lst4=[int(i) for i in input().split()]
# m=sum(lst1)
# a=0
# for i in range(4):
#     if (m == sum(lst2) and m == sum(lst3) and m == sum(lst4) and m == (lst1[0] + lst2[0] + lst3[0] + lst4[0]) and m == (lst1[1] + lst2[1] + lst3[1] + lst4[1]) and m == (lst1[2] + lst2[2] + lst3[2] + lst4[2]) and m == (lst1[3] + lst2[3] + lst3[3] + lst4[3])): 
#         a=2
# if a == 2:
#     print("magic")
# else:
#     print("not magic")

# '''
# Problem J3: Hidden Palindrome
# '''
# lst=[i for i in input()]
# def rec(j):
#     for i in range(len(lst)):
#         if lst[i-j] == lst[i+j] and i-j>=0 and i+j<=len(lst):
#             return rec(j+1)
#         else:
#             return j
# print(rec(1))

# '''
# Problem J4: Arrival Time
# '''
# lst=[int(i) for i in input().split(":")]
# mins=lst[0]*60+lst[1]
# dis=240
# while dis:
#     if mins >=1440:
#         mins = mins-1440
#     if (mins < 420 or mins >= 600) and (mins < 900 or mins >= 1140):
#         dis=dis-2
#         mins = mins+1
#     else:
#         dis=dis-1
#         mins = mins+1
# h='%02d' % int(mins/60)
# m='%02d' % (mins%60)
# print(h,":",m)

# '''
# Problem J5: Tandem Bicycle
# '''
# a=int(input())
# b=int(input())
# c=0
# lst1=[int(i) for i in input().split()]
# lst2=[int(i) for i in input().split()]
# if a == 1:
#     while len(lst1):
#         c=c+max(max(lst1),max(lst2))
#         del lst1[lst1.index(max(lst1))]
#         del lst2[lst2.index(max(lst2))]
#     print(c)
# elif a == 2:
#     while len(lst1):
#         c=c+max(max(lst1),min(lst2))
#         del lst1[lst1.index(max(lst1))]
#         del lst2[lst2.index(min(lst2))]
#     print(c)