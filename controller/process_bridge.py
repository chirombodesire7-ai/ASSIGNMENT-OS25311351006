import subprocess
import os

def run_c_scheduler(choice=1):
    project_root = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
    exe_path = os.path.join(project_root, "c_core", "eduos.exe")

    if not os.path.exists(exe_path):
        print("Missing C executable:", exe_path)
        return

    subprocess.run([exe_path], cwd=os.path.dirname(exe_path))