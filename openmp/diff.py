srednia_czasu = [
    [136.8, 277.8, 1911.5, 17309.7, 166626.2, 333925.8, 883908.6, 1697904.0, 3375407.8, 8437758.0],
    [49.6, 234.8, 2202.3, 21787.5, 214525.1, 429974.8, 1096327.6, 2197720.1, 4349620.9, 10775708.7]
]

for i in range(10):
    new = int(((srednia_czasu[0][i] - srednia_czasu[1][i]) / srednia_czasu[1][i]) * 100)
    print(f"Wartość {srednia_czasu[0][i]} zmniejszyła się od {srednia_czasu[1][i]} o {new} %")
    