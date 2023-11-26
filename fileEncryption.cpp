#include <bitset>
#include "fileEncryption.h"

FileEncryption::FileEncryption(uint64_t key) :
        des(key) {
}

int FileEncryption::encrypt(string input, string output) {
    return cipher(input, output, false);
}

int FileEncryption::decrypt(string input, string output) {
    return cipher(input, output, true);
}

int FileEncryption::cipher(string input, string output, bool decrypt) {
    // Open the input file for binary reading
    std::ifstream inFile(input, std::ios::binary | ios::ate);

    // Open the output file for binary writing
    std::ofstream outFile(output, std::ios::binary);

    // Read and encrypt the file in blocks
    const int blockSize = 8; // DES operates on 64-bit blocks (8 bytes)
    char buffer[blockSize];

    inFile.seekg(0, ios::beg);



//    for (size_t i = 0; i < ciphertext.length(); i += 16) {
//        string block = ciphertext.substr(i, 16);
//        uint64_t encryptedBlock = des.hexToUint64(block);
//        uint64_t decryptedBlock = des.decrypt(encryptedBlock);
//        decryptedText += des.uint64ToString(decryptedBlock);
//    }

    while (inFile.read((char*) &buffer, blockSize)) {
        if (decrypt) {
            string decryptedText;
            uint64_t encryptedBlock = des.hexToUint64(buffer);
            uint64_t decryptedBlock = des.decrypt(encryptedBlock);
            decryptedText += des.uint64ToString(decryptedBlock);

        } else {
            string ciphertext;
            string block = des.padString(string(buffer));
            uint64_t encryptedBlock = des.encrypt(des.stringToUint64(block));
            printf("encryptedBlock (hex): %016lX\n", encryptedBlock);
            outFile << std::hex <<(char*)&encryptedBlock;
        }


//        printf("enc: %016lX\n", enc_buffer);

    }

//    if (outFile.is_open()) {
//        outFile << std::hex << ciphertext;
//        outFile.close();
//        std::cout << "Ciphertext saved" << std::endl;
//    } else {
//        std::cerr << "Error opening the output file." << std::endl;
//    }

////    string ciphertext;
//    for (size_t i = 0; i < s.length(); i += 8) {
//        string block = s.substr(i, 8);
//        block = des.padString(block);
//        uint64_t encryptedBlock = des.encrypt(des.stringToUint64(block));
//        ciphertext += des.uint64ToHex(encryptedBlock);
//    }
//    printf("Encrypted text in hex: %s\n", ciphertext.c_str());
//
    // odszyfrowywanie





    // Close the files
    inFile.close();
    outFile.close();


    std::cout << "Encryption completed successfully." << std::endl;
    return 0;
    return 0;
}