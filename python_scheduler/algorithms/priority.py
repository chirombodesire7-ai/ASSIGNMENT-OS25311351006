from gantt import draw

def run(processes):
    processes = sorted(processes, key=lambda x: x["priority"])
    time = 0
    log = []

    print("\nPRIORITY SCHEDULING\n")

    for p in processes:
        start = time
        end = time + p["burst"]

        print(f"P{p['pid']} | WT={start} | TAT={end}")

        log.append({
            "pid": p["pid"],
            "start": start,
            "end": end
        })

        time = end

    draw(log)