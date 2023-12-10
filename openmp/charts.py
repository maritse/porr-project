import matplotlib.pyplot as plt

x_values = [1000, 10000, 100000, 200000, 500000, 1000000, 2000000, 5000000]

y_values_list = [
    [1911.5, 17309.7, 166626.2, 333925.8, 883908.6, 1697904.0, 3375407.8, 8437758.0],
    [2202.3, 21787.5, 214525.1, 429974.8, 1096327.6, 2197720.1, 4349620.9, 10775708.7]
]

plt.figure(figsize=(8, 6))

plt.plot(x_values, y_values_list[0], label='Serie 1', marker='o', linestyle='-', color='blue')
plt.plot(x_values, y_values_list[1], label='Serie 2', marker='x', linestyle='--', color='green')

plt.xlabel('Długość wiadomości')
plt.ylabel('Średni czas wykonania szyfrowania w sekundach [s]')
plt.title('Wykres średniego czasu trwania szyfrowania od długości wiadomości')

plt.legend(['OpenMP', 'Seq'])
plt.grid(True)

plt.show()
