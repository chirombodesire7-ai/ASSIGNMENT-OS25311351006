from process_bridge import run_c_scheduler
from report_generator import generate_report
from gantt_chart import draw_gantt

def main():
    print("RUNNING EDU OS CONTROLLER")

    run_c_scheduler(choice=1)

    generate_report()

    draw_gantt()

if __name__ == "__main__":
    main()