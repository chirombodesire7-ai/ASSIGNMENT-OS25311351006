import matplotlib.pyplot as plt

def draw_gantt(log):
    if not log:
        print("No Gantt data")
        return

    fig, ax = plt.subplots()

    y = 10

    for p in log:
        start = p["start"]
        end = p["end"]

        ax.barh(y, end - start, left=start)
        ax.text(start + (end - start)/2, y, f"P{p['pid']}", ha='center', va='center')

        y += 10

    ax.set_xlabel("Time")
    ax.set_yticks([])
    ax.set_title("Gantt Chart")

    plt.show()