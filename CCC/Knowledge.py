# '''
# Knowledge
# '''

# # r=input('请输入圆的半径：') #变量赋值
# # st='''XiaoMing said:" This is XiaoWang's book."''' #字符串的表示方法
# # lst=st.split('\'') #将字符串分隔成列表
# # ss='\''.join(lst)  #将列表的元素连接成字符串
# # print(f'圆的面积是:{2*3.14*r=:.2f}') #字符串中包括变量的写法
 
# # print(ss)
# for i in range(10):
#     print(i)
# else:
#     print('good')

# M=[
#     [1,2],
#     [3,4],
#     [5,6]
# ]
# row=len(M)
# col=len(M[0])

# '''
# 上下翻转
# '''
# for i in range(row // 2):
#     M[i], M[row-1-i] = M[row-1-i], M[i]
# print(M)

# '''
# 转置
# '''
# print([ [x[i] for x in M] for i in range(2) ])

# '''
# 左右翻转
# '''
# for m in M:
#   for i in range(col // 2):
#     m[i], m[col-1-i] = m[col-1-i], m[i]  
# print(M)


# m=list('1234567890')
# print([''.join(m[-1-i:]+m[:-1-i]) for i in range(len(m))])

# m='1234567890'
# print([m[-i-1:]+m[:-i-1] for i in range(len(m))])

'''
字符串和列表的操作比较
'''

print('查-------------')
ss='1231123'
print(ss.find('3')) # 2 find()函数如果查不到会返回一个-1

lst=[1,2,3,1,1,2,3]
print(lst.index(4)) # 2 index()函数如果查不到值会报错

print('改-------------')

ss="123hahahaha123"
ss=ss.replace('h','m',2)
print(ss) # '123mamahaha123'

ss="123hahahaha123"
ss=ss.strip('123') # 可以去除头尾指定字符，参数为空时，默认去除字符串中头尾的空格字符 lstrip(),rstrip()
print(ss) # 'hahahaha'

import re
s = '\tabc\t123\txyz\ropq\r'
t = re.sub('[\t\r]', '', s)
print(t) # 'abc123xyzopq'

lst=[1,2,3,1,1,2,3]
lst[2]='hello'
lst[3:5]='hello',4
print(lst) # [1,2,'hello',1,1,2,3]

print('增-------------')
ss=ss+'add'
lst.append('2')
lst.extend(('a','b'))
lst.insert(5,'insert')

print('删-------------')
ss=ss.replace('1','',1)

del lst[0]  # index
lst.pop(0)  # index
lst.remove(3) # value