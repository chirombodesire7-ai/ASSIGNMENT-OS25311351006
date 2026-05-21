import json

def generate_report(data):
    report_path = "../logs/controller_report.txt"

    with open(report_path, "w") as f:
        f.write("EDU OS REPORT\n\n")

        for p in data:
            f.write(
                f"PID {p['pid']} WT {p['waiting_time']} TAT {p['turnaround_time']}\n"
            )

    print("Report saved")