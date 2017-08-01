# coding: utf-8
import numpy as np

def softmax(x):
    if x.ndim == 2:
        x = x.T
        x = x - np.max(x, axis=0)
        y = np.exp(x) / np.sum(np.exp(x), axis=0)
        return y.T

    x = x - np.max(x) # 오버플로 대책
    return np.exp(x) / np.sum(np.exp(x))


x = np.array([-1, 0, 1.0])
y = softmax(x)

p = np.argmax(y) # 확률이 가장 높은 원소의 인덱스를 얻는다.

print(x)
print(y)
print(p)
'''
[-1.  0.  1.]
[ 0.09003057  0.24472847  0.66524096]
2

from Java
v = -1.000000, 0.000000, 1.000000
v2 = 0.090031, 0.244728, 0.665241

'''