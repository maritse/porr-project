#include <iostream>
#include <bitset>

using namespace std;

#include "tests.h"
#include "des3.h"
#include "des.h"
#include "fileEncryption.h"

void usage()
{
    cout << "Usage: ./des -e/-d <8-byte key> <input-file> <output-file>" << endl;
}

bitset<64> charToBitset(const char s[8])
{
    bitset<64> bits;
    for(int i=0; i<8; ++i)
        for(int j=0; j<8; ++j)
            bits[i*8+j] = ((s[i]>>j) & 1);
    return bits;
}

#include <sstream>
#include <iomanip>

std::string padString(const std::string& str) {
    std::string paddedStr = str;
    size_t paddingSize = 8 - (str.length() % 8);
    if (paddingSize != 8) {
        // Pad with null characters
        paddedStr.append(paddingSize, (char)(paddingSize));
    }
    return paddedStr;
}

std::string uint64ToHex(uint64_t value) {
    std::ostringstream oss;
    oss << std::hex << std::setw(16) << std::setfill('0') << value;
    return oss.str();
}

uint64_t hexToUint64(const std::string& hex) {
    uint64_t result;
    std::istringstream iss(hex);
    iss >> std::hex >> result;
    return result;
}

std::string uint64ToString(uint64_t value) {
    std::string result;
    for (int i = 0; i < 8; ++i) {
        char byte = static_cast<char>((value >> (i * 8)) & 0xFF);
        result.push_back(byte);
    }
    return result;
}

uint64_t stringToUint64(const std::string& str) {
    if (str.length() != 8) {
        // Handle error, input string should be exactly 8 characters
        return 0;
    }

    uint64_t result = 0;
    for (int i = 0; i < 8; ++i) {
        result |= static_cast<uint64_t>(static_cast<unsigned char>(str[i])) << ((7 - i) * 8);
    }

    return result;
}

int main(int argc, char **argv)
{
//    alltests(); return 0;


    if(argc < 3)
    {
        usage();
        return 1;
    }

    string mode = argv[1];
    if(mode != "-e" && mode != "-d")
    {
        usage();
        return 2;
    }

//    string input = "/home/mati/domains.txt";
//    string output = "/home/mati/domains.enc";
//    if (argc > 3)
//        input  = argv[3];
//
//    if (argc > 4)
//        output  = argv[4];

    ui64 key = strtoull(argv[2], nullptr, 16);
    printf("key (hex): %016lX\n", key);
    DES des(key);
//    ui64 input = 0x9474B8E8C73BCA7D;
    string s = "123456789";
//    s = padString(s);

    string ciphertext;
    for (size_t i = 0; i < s.length(); i += 8) {
        std::string block = s.substr(i, 8);
        block = padString(block);
        uint64_t encryptedBlock = des.encrypt(stringToUint64(block));
        ciphertext += uint64ToHex(encryptedBlock);
//        printf("cipher: %016lX\n", encryptedBlock);
    }
    printf("Encrypted text in hex: %s", ciphertext.c_str());

    return 0;
}