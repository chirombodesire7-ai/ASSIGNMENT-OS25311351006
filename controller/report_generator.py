import json

def generate_report():
    with open("c_core/pcb_snapshot.json", "r") as f:
        data = json.load(f)

    processes = data["processes"]

    with open("logs/eduos_report.txt", "w") as f:
        for p in processes:
            f.write(f"PID {p['pid']} WT {p['wt']} TAT {p['tat']}\n")
            