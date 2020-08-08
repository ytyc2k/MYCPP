'''
CCC Senior S1:Surmising a Sprinter’s Speed
'''
N=int(input('Please input an integer N (2<N<=1000):'))
data=[]
for i in range(N):
    data.append(list(map(int,input('Please input 2 integer, seperate with a space.').split())))
# data=[[20,-5],[0,-17],[10,31],[5,-3],[30,11],]
data.sort()
print(max(map(lambda x,y:abs(x[1]-y[1])/(x[0]-y[0]),data[1:],data[:-1])))