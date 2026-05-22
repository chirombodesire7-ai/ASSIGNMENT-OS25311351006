from gantt import draw

def run(processes, quantum):
    queue = processes.copy()
    time = 0
    log = []

    print("\nROUND ROBIN SCHEDULING\n")

    while queue:
        p = queue.pop(0)

        start = time
        exec_time = min(quantum, p["burst"])
        time += exec_time
        p["burst"] -= exec_time

        print(f"P{p['pid']} | EXEC={exec_time}")

        log.append({
            "pid": p["pid"],
            "start": start,
            "end": time
        })

        if p["burst"] > 0:
            queue.append(p)

    draw(log)