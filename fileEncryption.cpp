#include <bitset>
#include "fileEncryption.h"

FileEncryption::FileEncryption(ui64 key) :
        des(key)
{
}

int FileEncryption::encrypt(string input, string output)
{
    return cipher(input, output, false);
}

int FileEncryption::decrypt(string input, string output)
{
    return cipher(input, output, true);
}

int FileEncryption::cipher(string input, string output, bool decrypt)
{
//    // Open the input file for binary reading
//    std::ifstream inFile(input, std::ios::binary);
//
//    // Open the output file for binary writing
//    std::ofstream outFile(output, std::ios::binary);
//
//    // Read and encrypt the file in blocks
//    const int blockSize = 8; // DES operates on 64-bit blocks (8 bytes)
//    char buffer[blockSize];
//    uint64_t enc_buffer;
//
//    while (inFile.read(buffer, blockSize)) {
//
//        enc_buffer = des.encrypt((long)buffer);
//        printf("enc: %016lX\n", enc_buffer);
//        outFile.write(reinterpret_cast<const char*>(&enc_buffer), blockSize);
//    }
//
//    // Close the files
//    inFile.close();
//    outFile.close();
//
//
//
//    std::cout << "Encryption completed successfully." << std::endl;
//    return 0;

//    ifstream in;
//    ofstream out;
//    in.open(input, ios::binary);
//    out.open(output, ios::binary);
//    bitset<64> plain;
//    while(in.read((char*)&plain, sizeof(plain)))
//    {
//        bitset<64> cipher  = des.encrypt(plain.to_ullong());
//        printf("key: %016lX\n", cipher);
//        out.write((char*)&cipher, sizeof(cipher));
//        plain.reset();  // 置0
//    }
//    in.close();
//    out.close();
//    return 0;

    ifstream ifile;
    ofstream ofile;
    ui64 buffer;

    if (input.length()  < 1) input  = "/dev/stdin";
    if (output.length() < 1) output = "/dev/stdout";

    ifile.open(input,  ios::binary | ios::in | ios::ate);
    ofile.open(output, ios::binary | ios::out);

    ui64 size = ifile.tellg();
    ifile.seekg(0, ios::beg);

    ui64 block = size / 8;
    if (decrypt) block--;

    for (ui64 i = 0; i < block; i++)
    {
        ifile.read((char*) &buffer, 8);

        if (decrypt)
            buffer = des.decrypt(buffer);
        else {
            printf("enc: %016lX\n", buffer);
            buffer = des.encrypt(buffer);
            printf("enc: %016lX\n", buffer);
        }

        ofile.write((char*) &buffer, 8);
    }

//    if (!decrypt)
//    {
//        // Amount of padding needed
//        ui8 padding = 8 - (size % 8);
//
//        // Padding cannot be 0 (pad full block)
//        if (padding == 0)
//            padding  = 8;
//
//        // Read remaining part of file
//        buffer = (ui64) 0;
//        if(padding != 8)
//            ifile.read((char*) &buffer, 8 - padding);
//
//        // Pad block with a 1 followed by 0s
//        ui8 shift = padding * 8;
//        buffer <<= shift;
//        buffer  |= (ui64) 0x0000000000000001 << (shift - 1);
//
//        buffer = des.encrypt(buffer);
//        printf("enc: %016lX\n", buffer);
//        ofile.write((char*) &buffer, 8);
//    }
//    else
//    {
//        // Read last line of file
//        ifile.read((char*) &buffer, 8);
//        buffer = des.decrypt(buffer);
//
//        // Amount of padding on file
//        ui8 padding = 0;
//
//        // Check for and record padding on end
//        while(!(buffer & 0x00000000000000ff))
//        {
//            buffer >>= 8;
//            padding++;
//        }
//
//        buffer >>= 8;
//        padding++;
//
//        if(padding != 8)
//            ofile.write((char*) &buffer, 8 - padding);
//    }
//
    ifile.close();
    ofile.close();
    return 0;
}