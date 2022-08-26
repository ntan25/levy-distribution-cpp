import pandas as pd
import numpy as np 
import matplotlib.pyplot as plt


myfile = "levy-test.csv"
myfile_params = "levy-params.csv"
dat = pd.read_csv(myfile, header=None)
params = pd.read_csv(myfile_params, header=None)


c = params[0]
mu = params[1]

c = 0.5
mu=0

#work in progress what id like to have is the equation plotted alongisde the density plot
pdf = lambda x: np.sqrt(c/np.pi) * (np.exp(-1 * (c/(2 * (x)))) / np.power((x), 1.5))


sample_high = dat.max()
x_low = 1e-3
x_high = 1

x = np.linspace(x_low, x_high, 1000)
y = np.empty(0,dtype=float)

for num in x:
    toAdd = pdf(num)
    y = np.append(y, toAdd)
    
n_bins = 100


ax1 = plt.subplot(2, 1, 1)
ax2 = plt.subplot(2, 1, 2)
ax1.hist(dat, bins=n_bins)
ax1.set_ylabel("Sample Frequency")
ax1.set_xlim(left=0)

# ax1.set_xlabel("Variate")
ax1.set_title("Lévy Distribution Sample Density Plot")
ax2.plot(x, y, 'b')
ax2.set_xlim(left=x_low)
# ax2.set_title("Lévy Distribution PDF")
ax2.set_ylabel("Probability Density")
ax2.set_xlabel("Variate")

plt.show()