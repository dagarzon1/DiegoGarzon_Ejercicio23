import numpy as np
import matplotlib.pyplot as plt

data=np.loadtxt("datos.txt")

plt.plot(data[:,0], data[:,1], label="initial", color='b')
plt.plot(data[:,0], data[:,2], label="t=1 s", color='r')
plt.plot(data[:,0], data[:,3], label="t=2 s", color='k')
plt.plot(data[:,0], data[:,4], label="t=3 s", color='g')

plt.legend()
plt.savefig("grafica.pdf")
