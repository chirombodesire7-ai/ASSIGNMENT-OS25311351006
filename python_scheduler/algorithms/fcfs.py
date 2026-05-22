from gantt import draw

def run(processes):
    time = 0
    log = []

    print("\nFCFS SCHEDULING\n")

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
    