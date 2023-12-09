import subprocess
import random
import string

input_strings = [
    random.choice(string.printable)*10**3,
    random.choice(string.printable)*10**4,
    random.choice(string.printable)*10**5,
    random.choice(string.printable)*2*10**5,
    random.choice(string.printable)*5*10**5,
    random.choice(string.printable)*10**6,
    random.choice(string.printable)*2*10**6,
    random.choice(string.printable)*5*10**6,
    
]

your_program = "cmake-build-debug/porr_project"  # Replace with the actual path to your Python program

for input_string in input_strings:
    print(f"Starting program with input of lenght {len(input_string)}")
    process = subprocess.Popen(['time', your_program, "-e", "ee55de915785399e", "e0b3c7c32f48d42d", "8535ef460fb52fbc"], stdin=subprocess.PIPE, stdout=subprocess.PIPE, text=True)
    output, _ = process.communicate(input=input_string)
    print("")

