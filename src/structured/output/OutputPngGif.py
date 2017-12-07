from numpy import loadtxt, reshape
import matplotlib.pyplot as plt
from glob import glob
import imageio
plt.ioff()

filenames = glob("./output_*.dat")
filenames.sort()

for filename in filenames:
    fig = plt.figure(figsize=(6,6))
    ax = fig.add_subplot(111)
    
    file = open(filename, 'r')

    xCells = int(file.readline().split()[1])
    yCells = int(file.readline().split()[1])
    ghostCells = int(file.readline().split()[1])
    time = float(file.readline().split()[1])
    cfl = float(file.readline().split()[1])

    file.close()

    x,y,u = loadtxt(filename, skiprows=5, unpack=True)

    x = reshape(x, (xCells + 2 * ghostCells, yCells + 2 * ghostCells))
    y = reshape(y, (xCells + 2 * ghostCells, yCells + 2 * ghostCells))
    u = reshape(u, (xCells + 2 * ghostCells, yCells + 2 * ghostCells))


    cs = ax.contourf(x, y, u)
    fig.colorbar(cs, ax=ax)
    ax.set_title("CFL = %1.3f Time = %5.3f" % (cfl, time))
    fig.savefig(filename.replace(".dat", ".png"))
    
images = []
output_name = ("sim_cfl%1.3f.gif" % cfl)
for filename in filenames:
    images.append(imageio.imread(filename.replace('.dat', '.png')))
imageio.mimsave(output_name, images)