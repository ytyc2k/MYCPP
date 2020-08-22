print(max([bin(i).count('1') for i in range(100)]))

# ss='1111110'
# print([n for i in range(7) if (n:=int(ss[-i-1:]+ss[:-i-1],2)) < 100])

# lst=[[] for j in range(7)]
# for j in range(7):
#    for i in range(100):
#        if list(f'{bin(i):0>7}')[-j-1]=='1':
#            lst[-j-1].append(i)
#    print(7-j, lst[-j-1])
