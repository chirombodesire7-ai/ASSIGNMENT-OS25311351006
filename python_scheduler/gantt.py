from visualizer import draw_gantt

def draw(log):
    if not log:
        print("\nGANTT CHART\nNo data")
        return

    print("\nGANTT CHART\n")

    for item in log:
        print(f"[P{item['pid']}]", end=" ")

    print("\n")

    for item in log:
        print(f"{item['start']} -> {item['end']}", end=" ")

    print("\n")

    draw_gantt(log)