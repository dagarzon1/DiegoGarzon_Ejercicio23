import numpy as np
import matplotlib.pyplot as plt

data=np.loadtxt("datos.txt")
x=np.linspace(0.0,1.0,200)
for i in range(1,data.shape[1]):
    if(data[50,i]==1.0):
        plt.plot(x, data[:,i])
    if(data[50,i]<=-0.52 and data[50,i]>=-0.52):
        plt.plot(x, data[:,i])
    if(data[50,i]>=0.5 and data[50,i]>=-0.52):
        plt.plot(x, data[:,i])
    if(data[50,i]==-1.0):
        plt.plot(x, data[:,i])



plt.legend()
plt.savefig("grafica.pdf")
