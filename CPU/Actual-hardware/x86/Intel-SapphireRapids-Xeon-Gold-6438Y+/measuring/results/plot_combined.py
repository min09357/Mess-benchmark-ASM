import glob
import os

import pandas as pd
import matplotlib.pyplot as plt


SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
MEM_MAX_BW = 1 * 8 * 4800 / 1000  # GB/s: mem-max-channels * 8B * mem-freq(MT/s) / 1000


def main():
    csv_paths = sorted(
        glob.glob(os.path.join(SCRIPT_DIR, "*", "output", "bandwidth-latency.csv"))
    )
    if not csv_paths:
        raise SystemExit(f"No bandwidth-latency.csv found under {SCRIPT_DIR}/*/output/")

    fig, ax = plt.subplots(figsize=(16, 9))
    cmap = plt.get_cmap("tab10")

    for i, path in enumerate(csv_paths):
        label = os.path.basename(os.path.dirname(os.path.dirname(path)))
        df = pd.read_csv(path)
        ax.plot(
            df["bandwidth_smooth"],
            df["latency_smooth"],
            color=cmap(i % 10),
            linewidth=2,
            label=label,
        )

    ax.set_xlim(0, 1.05 * MEM_MAX_BW)
    ax.axvline(MEM_MAX_BW, color="gray", linestyle=":", linewidth=2)
    ymin, ymax = ax.get_ylim()
    ax.text(
        MEM_MAX_BW,
        ymin + 0.95 * (ymax - ymin),
        f"Max. theoretical BW = {MEM_MAX_BW:.1f} GB/s",
        ha="right",
        va="top",
    )

    ax.set_xlabel("Used Memory bandwidth [GB/s]")
    ax.set_ylabel("Memory access latency [ns]")
    ax.legend(loc="best")
    fig.tight_layout()

    for ext in ("pdf", "png"):
        out_path = os.path.join(SCRIPT_DIR, f"bandwidth-latency_combined.{ext}")
        fig.savefig(out_path, bbox_inches="tight")
        print(f"Saved: {out_path}")


if __name__ == "__main__":
    main()
