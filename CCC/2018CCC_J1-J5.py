# #######################################
#  @ Canadian Computing Competition     #
#  @ Junior 2018                        #
#  @ Author : Jun Yang                  #
#  @ Time   : 2020-08-27                #
# #######################################

# '''
# Problem J1: Telemarketer or not?
# '''
# lst=[]
# for i in range(4):
#     lst.append(input())
# if lst[0] > 7 and lst[0] < 10 and lst[1] == lst[2] and lst[3] > 7 and lst[3] < 10:
#     print('ignore')
# else:
#     print('answer')

# '''
# Problem J2: Occupy parking
# '''
# a=int(input())
# b=0
# str1=input()
# str2=input()
# for i in range(a):
#     if str1[i] == str2[i] and str1[i]== 'C':
#         b=b+1
# print(b)

# '''
# Problem J3: Are we there yet?
# '''
# dlst=input().split()
# dlst = [int(i) for i in dlst]
# for i in range(5):
#     if i == 0:
#         print(0,dlst[0],dlst[0]+dlst[1],dlst[0]+dlst[1]+dlst[2],dlst[0]+dlst[1]+dlst[2]+dlst[3],sep=' ')
#     elif i == 1:
#         print(dlst[0],0,dlst[1],dlst[1]+dlst[2],dlst[1]+dlst[2]+dlst[3],sep=' ')
#     elif i == 2:
#         print(dlst[0]+dlst[1],dlst[1],0,dlst[2],dlst[2]+dlst[3],sep=' ')
#     elif i == 3:
#         print(dlst[0]+dlst[1]+dlst[2],dlst[1]+dlst[2],dlst[2],0,dlst[3],sep=' ')
#     elif i == 4:
#         print(dlst[0]+dlst[1]+dlst[2]+dlst[3],dlst[1]+dlst[2]+dlst[3],dlst[2]+dlst[3],dlst[3],0,sep=' ')

# '''
# Problem J4/S2: Sunflowers
# '''
# n=int(input())
# lst=[]
# def flip90_left(data):
#     for row_index in range(len(data)):
#         for col_index in range(row_index,len(data[row_index])):
#             temp = data[row_index][col_index]
#             data[row_index][col_index] = data[col_index][row_index]
#             data[col_index][row_index] = temp
#     data=data[::-1]
#     return data
# for i in range(n):
#     lst.append([int(s) for s in input().split(" ")])
# for i in range(n):
#     for j in range(n):
#         lst[i][j]=int(lst[i][j])
# for i in range(n-1):
#     for j in range(n-1):
#         if lst[i][j] > lst[i][j+1] or (lst[i+1][j]-lst[i+1][j+1]) > (lst[i][j+1]-lst[i][j]) or lst[i][j]>lst[i+1][j]:
#             lst=flip90_left(lst)
# for i in range(n):
#     print(lst[i])

'''
Problem J5: Choose your own path
'''
