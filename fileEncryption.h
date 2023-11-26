#ifndef FILEENCRYPTION_H
#define FILEENCRYPTION_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "des3.h"

class FileEncryption {
public:
    FileEncryption(uint64_t key);

    int encrypt(string input, string output);

    int decrypt(string input, string output);

    int cipher(string input, string output, bool decrypt);

private:
    DES des;
};

#endif // FILEENCRYPTION_H
