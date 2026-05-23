from algorithms import fcfs, sjf, round_robin, priority

from loader import load_processes

from metrics import calculate_metrics
from dashboard import show_dashboard


def menu():
    print("\nPYTHON SCHEDULER SYSTEM\n")
    print("1. FCFS")
    print("2. SJF")
    print("3. ROUND ROBIN")
    print("4. PRIORITY")
    print("5. COMPARISON DASHBOARD")
    print("0. EXIT")


def get_processes():
    data = load_processes()

    if data:
        return data

    return [
        {"pid": 1, "burst": 6, "priority": 2},
        {"pid": 2, "burst": 3, "priority": 1},
        {"pid": 3, "burst": 8, "priority": 3},
        {"pid": 4, "burst": 4, "priority": 2}
    ]


while True:

    menu()

    try:
        choice = int(input("Select: "))
    except:
        print("Invalid input")
        continue

    processes = get_processes()

    if choice == 1:
        fcfs.run(processes)

    elif choice == 2:
        sjf.run(processes)

    elif choice == 3:
        quantum = int(input("Quantum: "))
        round_robin.run(processes, quantum)

    elif choice == 4:
        priority.run(processes)

    elif choice == 5:

        results = {}

        fcfs_log = fcfs.run(processes)
        results["FCFS"] = calculate_metrics(processes, fcfs_log)

        sjf_log = sjf.run(processes)
        results["SJF"] = calculate_metrics(processes, sjf_log)

        priority_log = priority.run(processes)
        results["PRIORITY"] = calculate_metrics(processes, priority_log)

        rr_log = round_robin.run(processes, 2)
        results["ROUND ROBIN"] = calculate_metrics(processes, rr_log)

        show_dashboard(results)

    elif choice == 0:
        print("Exit")
        break

    else:
        print("Invalid option")