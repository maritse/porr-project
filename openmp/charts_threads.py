import matplotlib.pyplot as plt

"""
1 thread - 2475495.7
2 thread - 
3 thread - 
4 thread - 
"""


x_values = [5, 6, 8, 10]

y_values_list = [
    [152094601.0, 166405878.0, 224550263.0, 266364262.0], # 100mkn
    [120590306.0, 134713111.0, 191275419.0, 211001291.0],  # 80 mln
    [75657528.0, 84138649.0, 117310365.0, 141898394.0], # 50 mln
    [30538599.0, 32692948.0, 43636105.0, 63411144.0], # 20 mln
    [15166572.0, 16725476.0, 21449213.0, 30330893.0] # 10 mln
]

plt.figure(figsize=(8, 6))

plt.scatter(x_values, y_values_list[0], s=100, label='Serie 1', marker='o', linestyle='-', color='red')
plt.scatter(x_values, y_values_list[1], s=100, label='Serie 1', marker='o', linestyle='-', color='green')
plt.scatter(x_values, y_values_list[2], s=100, label='Serie 1', marker='o', linestyle='-', color='blue')
plt.scatter(x_values, y_values_list[3], s=100, label='Serie 1', marker='o', linestyle='-', color='c')
plt.scatter(x_values, y_values_list[4], s=100, label='Serie 1', marker='o', linestyle='-', color='#e377c2')

plt.xlabel('Liczba wątków')
plt.ylabel('Średni czas wykonania szyfrowania w sekundach [s]')
plt.title('Wykres średniego czasu trwania szyfrowania od liczby wątków')
plt.xticks(x_values, x_values)

plt.legend(['100mln', '80mln', '50mln', '20mln', '10mln'])
plt.grid(True)
plt.plot(x_values, y_values_list[0], color='red')
plt.plot(x_values, y_values_list[1], color='green')
plt.plot(x_values, y_values_list[2], color='blue')
plt.plot(x_values, y_values_list[3], color='c')
plt.plot(x_values, y_values_list[4], color='#e377c2')

plt.show()
