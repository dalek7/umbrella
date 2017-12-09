import numpy as np

a = np.array([1,2,3,4])
b = np.array([5,6,7,8])

c = np.vstack((a,b))
print(c)
'''
[[1 2 3 4]
 [5 6 7 8]]
'''

d = np.hstack((a,b))
print(d)
'''
[1 2 3 4 5 6 7 8]
'''

a = np.array([1,2,3,4])[np.newaxis]
b = np.array([5,6,7,8])[np.newaxis]

print(a.T)
'''
[[1]
 [2]
 [3]
 [4]]
'''
c = np.hstack((a.T,b.T))
print(c)
'''
[[1 5]
 [2 6]
 [3 7]
 [4 8]]
 '''