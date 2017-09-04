

import matplotlib.pyplot as plt
import itertools
from matplotlib import style
import numpy as np

style.use('ggplot')

x = []
y = []
with open('x_y.txt', 'r') as f:
    for indx, line in enumerate(f):
        if indx % 2 == 0:
            x.append(line.strip())
        else:
            y.append(line.strip())

    fig = plt.scatter(x,y)
    plt.title('Sampled Objects')
    plt.ylabel('Y axis')
    plt.xlabel('X axis')
    plt.show()
