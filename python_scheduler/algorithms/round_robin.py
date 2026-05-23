from gantt import draw
from metrics import calculate_metrics, print_metrics


def run(processes, quantum):

    queue = []

    for p in processes:
        queue.append({
            "pid": p["pid"],
            "burst": p["burst"],
            "remaining": p["burst"]
        })

    time = 0
    log = []

    print("\nROUND ROBIN SCHEDULING\n")

    completed = {}

    while queue:

        p = queue.pop(0)

        start = time

        exec_time = min(quantum, p["remaining"])

        time += exec_time
        p["remaining"] -= exec_time

        print(f"P{p['pid']} | EXEC={exec_time}")

        log.append({
            "pid": p["pid"],
            "start": start,
            "end": time,
            "burst": exec_time
        })

        if p["remaining"] > 0:
            queue.append(p)
        else:
            completion = time

            tat = completion
            wt = tat - p["burst"]

            completed[p["pid"]] = {
                "pid": p["pid"],
                "wt": wt,
                "tat": tat,
                "burst": p["burst"]
            }

    draw(log)

    final_log = list(completed.values())

    metrics = calculate_metrics(processes, final_log)

    print_metrics("ROUND ROBIN", metrics)

    return final_log