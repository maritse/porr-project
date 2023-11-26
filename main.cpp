#include <iostream>
#include <bitset>
#include <sstream>
#include <iomanip>

using namespace std;

#include "tests.h"
#include "des3.h"
#include "des.h"
#include "fileEncryption.h"

void usage() {
    cout << "Usage: ./des -e/-d <8-byte key> <input-file> <output-file>" << endl;
}

int main(int argc, char **argv) {
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

    string input = "/home/mati/domains.txt";
    string output = "/home/mati/domains.enc";
//    if (argc > 3)
//        input  = argv[3];
//
//    if (argc > 4)
//        output  = argv[4];

    uint64_t key = strtoull(argv[2], nullptr, 16);
    printf("key (hex): %016lX\n", key);
    DES des(key);

    FileEncryption fe(key);

    fe.encrypt(input, output);

//    string s = "123456789";

//    // szyfrowanie
//    string ciphertext;
//    for (size_t i = 0; i < s.length(); i += 8) {
//        string block = s.substr(i, 8);
//        block = des.padString(block);
//        uint64_t encryptedBlock = des.encrypt(des.stringToUint64(block));
////        printf("encryptedBlock (hex): %016lX\n", encryptedBlock);
//        ciphertext += des.uint64ToHex(encryptedBlock);
//    }
//    printf("Encrypted text in hex: %s\n", ciphertext.c_str());
//
//    // odszyfrowywanie
//    string decryptedText;
//    for (size_t i = 0; i < ciphertext.length(); i += 16) {
//        string block = ciphertext.substr(i, 16);
//        uint64_t encryptedBlock = des.hexToUint64(block);
//        uint64_t decryptedBlock = des.decrypt(encryptedBlock);
//        decryptedText += des.uint64ToString(decryptedBlock);
//    }
//
//    printf("Decrypted text: %s\n", decryptedText.c_str());

    return 0;
}