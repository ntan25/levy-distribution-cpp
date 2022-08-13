import pandas as pd
import numpy as np 
import matplotlib.pyplot as plt


myfile = "levy-test.csv"
myfile_params = "levy-params.csv"
dat = pd.read_csv(myfile, header=None)
params = pd.read_csv(myfile_params, header=None)


c = params[0]
mu = params[1]


#work in progress what id like to have is the equation plotted alongisde the density plot
pdf = lambda x: np.sqrt(c/np.pi) * (np.exp(-1 * (c/(2 * (x-mu)))) / np.power((x-mu), 1.5))


x_low = dat.min()
x_high = dat.max()

x = np.linspace(x_low, x_high, 1000)

n_bins = 100

plt.hist(dat, bins=n_bins)
plt.ylabel("Frequency")
plt.xlabel("Variate")
plt.title("Lévy Distribution Density Plot")
plt.show()