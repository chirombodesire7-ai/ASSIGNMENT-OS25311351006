import json
import os

def load_processes():
    path = "../c_core/pcb_snapshot.json"

    if not os.path.exists(path):
        print("No PCB snapshot found")
        return []

    with open(path, "r") as f:
        data = json.load(f)

    processes = []

    for p in data.get("processes", []):
        processes.append({
            "pid": p["pid"],
            "burst": p["burst"],
            "priority": 1
        })

    return processes