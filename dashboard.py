import matplotlib.pyplot as plt
from metrics import calculate_metrics
from dashboard import show_dashboard


def show_dashboard(results):

    names = []
    avg_wt = []
    avg_tat = []

    for name, metrics in results.items():
        names.append(name)
        avg_wt.append(metrics["avg_wt"])
        avg_tat.append(metrics["avg_tat"])

    plt.figure(figsize=(10, 5))

    plt.bar(names, avg_wt)

    plt.title("Average Waiting Time")
    plt.xlabel("Algorithms")
    plt.ylabel("Waiting Time")

    plt.show()

    plt.figure(figsize=(10, 5))

    plt.bar(names, avg_tat)

    plt.title("Average Turnaround Time")
    plt.xlabel("Algorithms")
    plt.ylabel("Turnaround Time")

    plt.show()