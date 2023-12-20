ALL_LEN_4_CORES = [{'text length': 10, 'measurement': [153], 'average': 153.0}, {'text length': 100, 'measurement': [284], 'average': 284.0}, {'text length': 1000, 'measurement': [1655], 'average': 1655.0}, {'text length': 10000, 'measurement': [46876], 'average': 46876.0}, {'text length': 100000, 'measurement': [194598], 'average': 194598.0}, {'text length': 200000, 'measurement': [404915], 'average': 404915.0}, {'text length': 500000, 'measurement': [883488], 'average': 883488.0}, {'text length': 1000000, 'measurement': [3914336], 'average': 3914336.0}, {'text length': 2000000, 'measurement': [5444051], 'average': 5444051.0}, {'text length': 5000000, 'measurement': [10930590], 'average': 10930590.0}, {'text length': 10000000, 'measurement': [20433307], 'average': 20433307.0}, {'text length': 20000000, 'measurement': [47824786], 'average': 47824786.0}, {'text length': 50000000, 'measurement': [120086554], 'average': 120086554.0}, {'text length': 80000000, 'measurement': [204251070], 'average': 204251070.0}, {'text length': 100000000, 'measurement': [242889359], 'average': 242889359.0}]

HIGH_LEN_5_CORES = [{'text length': 1000000, 'measurement': [1389073], 'average': 1389073.0}, {'text length': 2000000, 'measurement': [2949712], 'average': 2949712.0}, {'text length': 5000000, 'measurement': [7643609], 'average': 7643609.0}, {'text length': 10000000, 'measurement': [15166572], 'average': 15166572.0}, {'text length': 20000000, 'measurement': [30538599], 'average': 30538599.0}, {'text length': 50000000, 'measurement': [75657528], 'average': 75657528.0}, {'text length': 80000000, 'measurement': [120590306], 'average': 120590306.0}, {'text length': 100000000, 'measurement': [152094601], 'average': 152094601.0}]

HIGH_LEN_6_CORES = [{'text length': 1000000, 'measurement': [1654506], 'average': 1654506.0}, {'text length': 2000000, 'measurement': [3321402], 'average': 3321402.0}, {'text length': 5000000, 'measurement': [8439953], 'average': 8439953.0}, {'text length': 10000000, 'measurement': [16725476], 'average': 16725476.0}, {'text length': 20000000, 'measurement': [32692948], 'average': 32692948.0}, {'text length': 50000000, 'measurement': [84138649], 'average': 84138649.0}, {'text length': 80000000, 'measurement': [134713111], 'average': 134713111.0}, {'text length': 100000000, 'measurement': [166405878], 'average': 166405878.0}]

HIGH_LEN_8_CORES = [{'text length': 1000000, 'measurement': [2210571], 'average': 2210571.0}, {'text length': 2000000, 'measurement': [4496982], 'average': 4496982.0}, {'text length': 5000000, 'measurement': [10623715], 'average': 10623715.0}, {'text length': 10000000, 'measurement': [21449213], 'average': 21449213.0}, {'text length': 20000000, 'measurement': [43636105], 'average': 43636105.0}, {'text length': 50000000, 'measurement': [117310365], 'average': 117310365.0}, {'text length': 80000000, 'measurement': [191275419], 'average': 191275419.0}, {'text length': 100000000, 'measurement': [224550263], 'average': 224550263.0}]

HIGH_LEN_10_CORES = [{'text length': 1000000, 'measurement': [2710774], 'average': 2710774.0}, {'text length': 2000000, 'measurement': [5546333], 'average': 5546333.0}, {'text length': 5000000, 'measurement': [13619033], 'average': 13619033.0}, {'text length': 10000000, 'measurement': [30330893], 'average': 30330893.0}, {'text length': 20000000, 'measurement': [63411144], 'average': 63411144.0}, {'text length': 50000000, 'measurement': [141898394], 'average': 141898394.0}, {'text length': 80000000, 'measurement': [211001291], 'average': 211001291.0}, {'text length': 100000000, 'measurement': [266364262], 'average': 266364262.0}]



ALL_HIGH = [HIGH_LEN_5_CORES, HIGH_LEN_6_CORES, HIGH_LEN_8_CORES, HIGH_LEN_10_CORES]
def pretty_print(data):
    for one in data:
        print(str(one["average"]) + ",")



for core in ALL_HIGH:
    for one in core:
        if one["text length"] == 10000000:
            print(str(one["average"]) + ", ", end="")




