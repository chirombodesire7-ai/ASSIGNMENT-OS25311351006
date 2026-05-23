from gantt import draw
from metrics import calculate_metrics, print_metrics


def run(processes):

    processes = sorted(
        processes,
        key=lambda x: x["burst"]
    )

    time = 0
    log = []

    print("\nSJF SCHEDULING\n")

    for p in processes:

        start = time
        end = start + p["burst"]

        wt = start
        tat = end

        print(f"P{p['pid']} | WT={wt} | TAT={tat}")

        log.append({
            "pid": p["pid"],
            "start": start,
            "end": end,
            "burst": p["burst"],
            "wt": wt,
            "tat": tat
        })

        time = end

    draw(log)

    metrics = calculate_metrics(
        processes,
        log
    )

    print_metrics(
        "SJF",
        metrics
    )

    return log