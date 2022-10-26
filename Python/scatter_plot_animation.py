from matplotlib import pyplot as plt
from matplotlib.animation import FuncAnimation
import random
import numpy as np

x = []
y = []
colors = []
fig = plt.figure(figsize=(7,5))

def animation_func(i):
	x.append(random.randint(0,100))
	y.append(random.randint(0,100))
	colors.append(np.random.rand(1))
	area = random.randint(0,30) * random.randint(0,30)
	plt.xlim(0,100)
	plt.ylim(0,100)
	plt.scatter(x, y, c = colors, s = area, alpha = 0.5)

animation = FuncAnimation(fig, animation_func,
						interval = 100)
plt.show()
