#ifndef TESTS_H
#define TESTS_H

#include "des3.h"

void test(ui64 input, ui64 key)
{
    DES des(key);

    ui64 result = des.encrypt(input);
    printf("E: %016lX\n", result);

    result = des.decrypt(result);
    printf("D: %016lX\n", result);
    printf("P: %016lX\n", input);
}

void test1()
{
    ui64 input = 0x9474B8E8C73BCA7D;
    ui64 key   = 0x0000000000000123;
    test(input, key);
    printf("\n");
}

void test2()
{
    test(0x0000000000000000, 0x0000000000000000);
    test(0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF);
    printf("\n");
}

void test3()
{
    DES3 des(0x51a264ae19b71531, 0xb95374ba8ddff8c1, 0x1234123412341234);
    ui64 input = 0x1111111111111111;

    ui64 result = des.encrypt(input);
    printf("E: %016lX\n", result);

    result = des.decrypt(result);
    printf("D: %016lX\n", result);
    printf("P: %016lX\n", input);
}


void alltests()
{
    printf("Test 1\n");
    test1();
    printf("Test 2\n");
    test2();
    printf("Test 3\n");
    test3();

}

#endif // TESTS_H