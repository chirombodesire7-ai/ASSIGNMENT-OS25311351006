import json

def load_processes():
    with open("../c_core/pcb_snapshot.json", "r") as f:
        return json.load(f)