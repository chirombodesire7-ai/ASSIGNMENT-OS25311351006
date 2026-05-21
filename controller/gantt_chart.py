import json
import matplotlib.pyplot as plt

def draw_gantt():
    with open("../c_core/pcb_snapshot.json", "r") as f:
        data = json.load(f)

    pids = [p["pid"] for p in data]
    wt = [p["waiting_time"] for p in data]
    tat = [p["turnaround_time"] for p in data]

    plt.bar(pids, tat)
    plt.xlabel("Process ID")
    plt.ylabel("Turnaround Time")
    plt.title("EDU OS Gantt View")
    plt.show()

if __name__ == "__main__":
    draw_gantt()