import matplotlib.pyplot as plt

x_values = [10, 
            100, 
            1000, 
            10000, 
            100000, 
            200000, 
            500000, 
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
    [
        136.8, # 10 
        277.8, # 100
        1911.5, # 1000
        17309.7, # 10000
        166626.2, # 100000
        333925.8, # 200000
        883908.6, # 500000
        1697904.0, # 1000000
        3375407.8, # 2000000
        8437758.0, # 5000000
        16538500.0, # 10000000
        31512428.0, # 20000000 
        77586877.0,  # 50000000 
        125475623.0,  # 80000000
        157303243.0], # 100000000
    [
        49.6, # 10
        234.8, # 100
        2202.3, # 1000
        21787.5, # 10000
        214525.1, # 100000
        429974.8, # 200000
        1096327.6, # 500000
        2197720.1, # 1000000
        4349620.9, # 2000000
        10775708.7, # 5000000
        20720039.0, # 10000000
        42666828.0,   # 20000000 
        103868265.0,   # 50000000 
        169228848.0,   # 80000000 
        209576014.0# 100000000
     ],
     [
        153.0,
        284.0,
        1655.0,
        46876.0,
        194598.0,
        404915.0,
        883488.0,
        3914336.0,
        5444051.0,
        10930590.0,
        20433307.0,
        47824786.0,
        120086554.0,
        204251070.0,
        242889359.0
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

plt.plot(x_values, y_values_list[0], label='Serie 1', marker='o', linestyle='-', color='blue')
plt.plot(x_values, y_values_list[1], label='Serie 2', marker='x', linestyle='--', color='green')
plt.plot(x_values, y_values_list[2], label='Serie 3', marker='x', linestyle='--', color='red')


plt.xlabel('Długość wiadomości')
plt.ylabel('Średni czas wykonania szyfrowania w sekundach [s]')
plt.title('Wykres średniego czasu trwania szyfrowania od długości wiadomości')

plt.legend(['OpenMP 2c', 'Seq', 'OpenMP 4c'])
plt.grid(True)

plt.show()
