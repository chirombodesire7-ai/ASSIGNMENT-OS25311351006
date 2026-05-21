import json
import matplotlib.pyplot as plt

def load_data(file_path):
with open(file_path, "r") as f:
return json.load(f)

def draw_gantt(data):
processes = data["processes"]

start = 0
for p in processes:
    plt.barh(p["name"], p["burst"], left=start)
    start += p["burst"]

plt.xlabel("Time")
plt.ylabel("Processes")
plt.title("FCFS Gantt Chart")
plt.show()

if name == "main":
data = load_data("pcb_snapshot.json")
draw_gantt(data)
