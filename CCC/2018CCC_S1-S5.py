# n=int(input())
# lst=[int(input()) for x in range(n)]
# lst.sort()
# nb=[]
# for i in range(1,len(lst)-1):
#     a=abs(lst[i+1]-lst[i])/2+abs(lst[i-1]-lst[i])/2
#     nb.append(a)
# nb.sort()
# print(nb[0])

# J4/S2

a=int(input())
def count(a):
    num = 0
    for i in range(2, a+1):
        if a % i < i:
            subtrees = 0
            if a // i > 1:
                subtrees += count(a//i)
                print(subtrees)
            else:
                subtrees += 1
            num += subtrees
    return num
print(count(a))

