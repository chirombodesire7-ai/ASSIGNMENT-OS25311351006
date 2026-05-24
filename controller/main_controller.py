from gantt_chart import draw_gantt


def main():

    data = [
        {"pid": 1, "start": 0, "end": 6},
        {"pid": 2, "start": 6, "end": 9},
        {"pid": 3, "start": 9, "end": 17},
        {"pid": 4, "start": 17, "end": 21}
    ]

    draw_gantt(data)


if __name__ == "__main__":
    main()