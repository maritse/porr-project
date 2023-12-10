import subprocess
import random
import string


input_strings = [
    #random.choice(string.printable)*10**1, #  10
    #andom.choice(string.printable)*10**2, #  100
    #random.choice(string.printable)*10**3, #  1000
    #random.choice(string.printable)*10**4, #  10000
    random.choice(string.printable)*10**5, #  100000
    #random.choice(string.printable)*2*10**5,# 200000
    #random.choice(string.printable)*5*10**5,# 500000
    #random.choice(string.printable)*10**6,  # 1000000
    #random.choice(string.printable)*2*10**6,# 2000000
    #random.choice(string.printable)*5*10**6,# 5000000

]

NUMBER_OF_TEST_CASES = 100

your_program = "build/porr_project"  # Replace with the actual path to your Python program

full_results = []

for input_string in input_strings:
    suma = 0
    temp_lista = []
    for i in range(NUMBER_OF_TEST_CASES):
        print(i)
        #print(f"Starting program with input of lenght {len(input_string)}", end="")
        #process = subprocess.Popen(['time', your_program, "-e", "ee55de915785399e", "e0b3c7c32f48d42d", "8535ef460fb52fbc"], stdin=subprocess.PIPE, stdout=subprocess.PIPE, text=True)
        process = subprocess.Popen([your_program, "-e", "ee55de915785399e", "e0b3c7c32f48d42d", "8535ef460fb52fbc"], stdin=subprocess.PIPE, stdout=subprocess.PIPE, text=True)    
        output, _ = process.communicate(input=input_string)
        #print(output)
        temp_lista.append(int(output))
    
    for one in temp_lista:
        suma += one
    print("Dla " + str(len(input_string)) + " srednia to " + str(suma / 100))

    full_results.append(temp_lista)

print(full_results)