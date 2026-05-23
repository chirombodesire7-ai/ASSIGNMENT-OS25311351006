import matplotlib.pyplot as plt


def show_dashboard(results):

    names = []
    avg_wt = []
    avg_tat = []

    for name, metrics in results.items():
        names.append(name)
        avg_wt.append(metrics["avg_wt"])
        avg_tat.append(metrics["avg_tat"])

    plt.figure()

    plt.bar(names, avg_wt)

    plt.title("Average Waiting Time")
    plt.xlabel("Algorithms")
    plt.ylabel("Time")

    plt.show()

    plt.figure()

    plt.bar(names, avg_tat)

    plt.title("Average Turnaround Time")
    plt.xlabel("Algorithms")
    plt.ylabel("Time")

    plt.show()