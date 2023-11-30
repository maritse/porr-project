#include <iostream>

using namespace std;

#include "tests.h"
#include "des3.h"
#include "des.h"

void usage() {
    cout << "Usage: ./des -e/-d <8-byte key1> <8-byte key2> <8-byte key3>" << endl;
}

int main(int argc, char **argv) {
    // testy
//    alltests(); return 0;


    if (argc < 3) {
        usage();
        return 1;
    }

    string mode = argv[1];
    if (mode != "-e" && mode != "-d") {
        usage();
        return 2;
    }

    uint64_t key1 = strtoull(argv[2], nullptr, 16);
    uint64_t key2 = strtoull(argv[3], nullptr, 16);
    uint64_t key3 = strtoull(argv[4], nullptr, 16);

    DES3 des(0, key1, key2, key3);

    string input;
    printf("Enter input plaintext (utf-8)/ciphertext (hex): ");
    cin >> input;
    printf("\n");

    if (mode == "-e") {
        // szyfrowanie
        string ciphertext;
        for (size_t i = 0; i < input.length(); i += 8) {
            string block = input.substr(i, 8);
            block = des.padString(block);
            uint64_t encryptedBlock = des.encrypt(des.stringToUint64(block));
            ciphertext += des.uint64ToHex(encryptedBlock);
        }
        printf("Encrypted text in hex: %s\n", ciphertext.c_str());
    } else {
        // odszyfrowywanie
        string decryptedText;
        for (size_t i = 0; i < input.length(); i += 16) {
            string block = input.substr(i, 16);
            uint64_t encryptedBlock = des.hexToUint64(block);
            uint64_t decryptedBlock = des.decrypt(encryptedBlock);
            decryptedText += des.uint64ToString(decryptedBlock);
        }
        printf("Decrypted text: %s\n", decryptedText.c_str());
    }
    return 0;
}