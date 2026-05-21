import json
import subprocess
import os

C_EXEC = "../c_core/eduos.exe"
JSON_FILE = "../c_core/pcb_snapshot.json"

def run_c_scheduler(choice, quantum=None):
    if quantum is None:
        cmd = [C_EXEC]
    else:
        cmd = [C_EXEC]

    process = subprocess.Popen(cmd)
    process.wait()

    with open(JSON_FILE, "r") as f:
        data = json.load(f)

    return data