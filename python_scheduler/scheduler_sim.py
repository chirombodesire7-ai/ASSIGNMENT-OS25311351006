from algorithms import fcfs
from algorithms import sjf
from algorithms import round_robin
from algorithms import priority

processes = [
    {"pid": 1, "burst": 6, "priority": 2},
    {"pid": 2, "burst": 3, "priority": 1},
    {"pid": 3, "burst": 8, "priority": 3},
    {"pid": 4, "burst": 4, "priority": 2}
]

def menu():
    print("\nPYTHON SCHEDULER SYSTEM\n")
    print("1. FCFS")
    print("2. SJF")
    print("3. ROUND ROBIN")
    print("4. PRIORITY")
    print("0. EXIT")

while True:
    menu()

    try:
        choice = int(input("Select: "))
    except:
        print("Invalid input")
        continue

    if choice == 1:
        fcfs.run(processes)

    elif choice == 2:
        sjf.run(processes)

    elif choice == 3:
        quantum = int(input("Quantum: "))
        round_robin.run(processes, quantum)

    elif choice == 4:
        priority.run(processes)

    elif choice == 0:
        print("Exit")
        break

    else:
        print("Invalid option")