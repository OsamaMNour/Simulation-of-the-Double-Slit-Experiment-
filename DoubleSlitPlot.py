import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

# Load the data from the file
data = np.loadtxt("photons.txt")

# Split the data into separate arrays for x, y, and intensity
x = data[:, 0]
y = data[:, 1]
intensity = data[:, 2]

# Create a scatter plot of the x and y positions, with the color of each point representing intensity
fig, ax = plt.subplots()
scatter = ax.scatter(x, y, c=intensity, cmap='viridis')
colorbar = plt.colorbar(scatter)
ax.set_xlabel('x position')
ax.set_ylabel('y position')
ax.set_title('Distribution of Photons after Double Slit')

def update(frame):
    scatter.set_offsets(np.c_[x[:frame], y[:frame]])
    scatter.set_array(intensity[:frame])
    return scatter,

ani = FuncAnimation(fig, update, frames=len(x), interval=50, blit=True)
plt.show()
