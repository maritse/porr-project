import matplotlib.pyplot as plt

"""
1 thread - 2475495.7
2 thread - 
3 thread - 
4 thread - 
"""


x_values = [1, 2, 3, 4]

y_values_list = [247549.5, 174395.4, 189840.3, 407933.4 ]

plt.figure(figsize=(8, 6))

plt.scatter(x_values, y_values_list, s=100, label='Serie 1', marker='o', linestyle='-', color='red')

plt.xlabel('Liczba wątków')
plt.ylabel('Średni czas wykonania szyfrowania (długość wiadomości 100000) w sekundach [s]')
plt.title('Wykres średniego czasu trwania szyfrowania od liczby wątków')
plt.xticks(x_values, x_values)

plt.legend(['OpenMP', 'Seq'])
plt.grid(True)

plt.show()
