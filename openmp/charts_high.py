import matplotlib.pyplot as plt

x_values = [
            1000000, 
            2000000, 
            5000000, 
            10000000,
            20000000,
            50000000,
            80000000,
            100000000
        ]

# 2 threads
y_values_list = [
    # 5 wątków
    [
        1389073.0,
        2949712.0,
        7643609.0,
        15166572.0,
        30538599.0,
        75657528.0,
        120590306.0,
        152094601.0
     ],
     # 6 wątków
     [
        1654506.0,
        3321402.0,
        8439953.0,
        16725476.0,
        32692948.0,
        84138649.0,
        134713111.0,
        166405878.0
     ],
     # 8 watkow
    [
        2210571.0,
        4496982.0,
        10623715.0,
        21449213.0,
        43636105.0,
        117310365.0,
        191275419.0,
        224550263.0
    ] ,
     # 10 watkow
     [
        2710774.0,
        5546333.0,
        13619033.0,
        30330893.0,
        63411144.0,
        141898394.0,
        211001291.0,
        266364262.0,
     ]
]

# 4 threads
"""
y_values_list = [
    [],
    []
]
"""

plt.figure(figsize=(8, 6))

plt.plot(x_values, y_values_list[0], label='Serie 1', marker='x', linestyle='-', color='blue')
plt.plot(x_values, y_values_list[1], label='Serie 2', marker='x', linestyle='--', color='green')
plt.plot(x_values, y_values_list[2], label='Serie 3', marker='x', linestyle='--', color='red')
plt.plot(x_values, y_values_list[3], label='Serie 3', marker='x', linestyle='--', color='purple')


plt.xlabel('Długość wiadomości')
plt.ylabel('Średni czas wykonania szyfrowania w sekundach [s]')
plt.title('Wykres średniego czasu trwania szyfrowania od długości wiadomości')

plt.legend(['5 core', '6 core', '8 core', '10 core'])
plt.grid(True)

plt.show()
