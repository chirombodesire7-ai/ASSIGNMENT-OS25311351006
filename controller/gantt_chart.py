import matplotlib.pyplot as plt


def draw_gantt(data):

    fig, ax = plt.subplots()

    y = 10

    for p in data:

        start = p["start"]
        duration = p["end"] - p["start"]

        ax.broken_barh(
            [(start, duration)],
            (y, 5)
        )

        ax.text(
            start + duration / 2,
            y + 2,
            f'P{p["pid"]}',
            ha='center',
            va='center',
            color='black'
        )

    ax.set_xlabel("Time")
    ax.set_ylabel("Processes")
    ax.set_title("Gantt Chart")

    plt.show()