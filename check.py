import numpy as np

mat_1 = []
mat_2 = []
mat_3 = []
size = 1000

data_1 = np.genfromtxt('C:\\Users\\D_20\\CLionProjects\\PP_lab1\\cmake-build-debug\\Mat_1.txt', dtype=int)
data_2 = np.genfromtxt('C:\\Users\\D_20\\CLionProjects\\PP_lab1\\cmake-build-debug\\Mat_2.txt', dtype=int)
multiplication = np.genfromtxt('C:\\Users\\D_20\\CLionProjects\\PP_lab1\\cmake-build-debug\\Res.txt', dtype=int)

r_1 = []
r_2 = []
r_3 = []

for i in data_1:
    r_1.append(i)
    if len(r_1) == size:
        mat_1.append(r_1.copy())
        r_1.clear()

for j in data_2:
    r_2.append(j)
    if len(r_2) == size:
        mat_2.append(r_2.copy())
        r_2.clear()

for k in multiplication:
    r_3.append(k)
    if len(r_3) == size:
        mat_3.append(r_3.copy())
        r_3.clear()

mat_1 = np.array(mat_1)
mat_2 = np.array(mat_2)
mat_3 = np.array(mat_3)
mt_1 = np.matrix(mat_1, dtype=int)
mt_2 = np.matrix(mat_2, dtype=int)
mt_3 = np.matrix(mat_3, dtype=int)

mul = np.dot(mt_1, mt_2)

mul = np.array(mul)
mt_3 = np.array(mt_3)
if np.array_equal(mul, mt_3):
    print('Good')
else:
    print('Bad')