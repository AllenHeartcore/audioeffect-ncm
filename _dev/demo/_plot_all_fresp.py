# import os

# os.chdir("../..")


import json
import matplotlib.pyplot as plt
from ncae.scheme import NCAEScheme


with open("_translate_plot.json", encoding="utf-8") as fin:
    schemes = json.load(fin)

fig, axs = plt.subplots(30, 11, figsize=(11 * 3, 30 * 2))

for (f, title), ax in zip(schemes.items(), axs.flatten()):

    s = NCAEScheme(f"presets/{f}.ncae")
    s.plugins[0].ir.plot(ax, title=title, show_axis=False, show_ticks=False)
    print(title)

fig.tight_layout()
fig.savefig("_dev/demo/fresp_plot.png")
