from matplotlib import pyplot as plt
from matplotlib import style
import numpy as np

style.use('ggplot')

x,y = np.genfromtxt('output.txt', unpack = True, delimiter = ',')

plt.scatter(x,y)

plt.title('Range Graph')
plt.ylabel('Y axis')
plt.xlabel('X axis')

plt.show()
