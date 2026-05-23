def calculate_metrics(processes, log):
    n = len(processes)

    total_wt = sum(p["wt"] for p in log)
    total_tat = sum(p["tat"] for p in log)

    avg_wt = total_wt / n
    avg_tat = total_tat / n

    total_time = max(p["end"] for p in log)
    burst_sum = sum(p["burst"] for p in processes)

    throughput = n / total_time
    cpu_util = (burst_sum / total_time) * 100

    return {
        "avg_wt": avg_wt,
        "avg_tat": avg_tat,
        "throughput": throughput,
        "cpu_util": cpu_util
    }


def print_metrics(name, metrics):
    print("\nMETRICS:", name)
    print("Average Waiting Time:", round(metrics["avg_wt"], 2))
    print("Average Turnaround Time:", round(metrics["avg_tat"], 2))
    print("Throughput:", round(metrics["throughput"], 2))
    print("CPU Utilization:", round(metrics["cpu_util"], 2), "%")