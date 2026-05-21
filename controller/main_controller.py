from process_bridge import run_c_scheduler
from report_generator import generate_report

def main():
    print("EDU OS CONTROLLER STARTED")

    print("Running C scheduler...")

    data = run_c_scheduler(choice=1)

    print("Generating report...")

    generate_report(data)

    print("DONE")

if __name__ == "__main__":
    main()