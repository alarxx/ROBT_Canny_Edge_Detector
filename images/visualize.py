import matplotlib
# matplotlib.use("QtAgg")
matplotlib.use("TkAgg")
print(matplotlib.get_backend())

import matplotlib.pyplot as plt
import matplotlib.image as mpimg

files = [
    "lenna.png",
    "gray.png",
    "blur.png",
    "Sobel.png",
    "nms_xy.png",
    "nms.png",
    "strongweak.png",
    "hysterisis.png",
]

rows, cols = 2, 4

fig, axes = plt.subplots(rows, cols, figsize=(16, 8))

for ax, fname in zip(axes.flat, files):
    img = mpimg.imread(fname)        # png/jpg
    ax.imshow(img, cmap="gray")      # cmap не мешает, если img уже RGB
    ax.set_title(fname, fontsize=10)
    ax.axis("off")

# если axes больше, чем файлов (на всякий случай)
for ax in axes.flat[len(files):]:
    ax.axis("off")

plt.tight_layout()
plt.show()
